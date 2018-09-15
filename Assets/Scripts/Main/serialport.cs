using UnityEngine;
using System.Collections;
using System.IO.Ports;
using System;

public class serialport : MonoBehaviour
{

    private SerialPort sp;
    private const int BUFFER_SIZE = 128;
    private byte[] frame16 = new byte[BUFFER_SIZE];
    private byte[] frame03 = new byte[BUFFER_SIZE];
    private byte state = 0;

    public string PortName = "COM4";
    private float Scan_Time = 0.03f; //0.03 Seconds

    //FUNCTION 03
    public long F03_requests = 0;
    public long F03_successful_requests = 0;
    public long F03_failed_requests = 0;
    public long F03_exception_errors = 0;

    private byte F03_Slave_Address = 1;
    private byte F03_Function = 3;
    private int F03_Starting_Address = 0;
    private int F03_NumberofRegisters = 8;
    private byte F03_Byte_Count;
    public int[] F03_values;

    public bool F03_valuesEnable = false;


    void OnGUI()
    {
        GUI.Label(new Rect(10, Screen.height - 35, Screen.width, 35), "MODBUS SLAVE=1, SERIAL PORT=" + PortName + ", BAUD=9600, PARITY=EVEN, DATA=8BIT, STOPBITS=ONE");
    }

    void Start()
    {
        Application.runInBackground = true;

        F03_values = new int[F03_NumberofRegisters]; 

        //public SerialPort(string portName, int baudRate, Parity parity, int dataBits, StopBits stopBits);
        sp = new SerialPort(PortName//端口名
                            , 9600// 波特率
                            , Parity.None//奇偶校验位
                            , 8// 数据位
                            , StopBits.One);//停止位

        OpenConnection();
        state = 0;
        InvokeRepeating("Modbus_Update", 1.0f, Scan_Time);//每隔Scan_Time运行一次这个函数：Modbus_Update()
    }

    public void OpenConnection()
    {
        if (sp != null)
        {
            try
            {
                sp.Open();
            }
            catch (Exception ex)
            {
                print(ex);
            }
        }
        if (sp.IsOpen)
        {
            sp.ReadTimeout = 1;//从有数据开始，读取的时间超过这个设置的值，则引发异常
            sp.WriteTimeout = 10;
            print(PortName + " Port Opened!");
            sp.BaseStream.Flush();//清除缓存
        }
    }
   
    void OnApplicationQuit()
    {
        if (sp != null)
        {
            if (sp.IsOpen) sp.Close();
        }
    }


    void end()
    {
        if (sp != null)
        {
            if (sp.IsOpen) sp.Close();
        }
    }


    int calculateCRC(byte[] crcframe, int bufferSize) //计算循环冗余校验码
    {
        int temp, temp2, flag;
        temp = 0xFFFF;
        for (int i = 0; i < bufferSize; i++)
        {
            temp = temp ^ crcframe[i];//位运算，按位异或
            for (int j = 1; j <= 8; j++)
            {
                flag = temp & 0x0001;
                temp >>= 1;
                if (flag == 1)
                    temp ^= 0xA001;
            }
        } 

        temp2 = temp >> 8;
        temp = (temp << 8) | temp2;
        temp &= 0xFFFF;
        return temp;
    }

    void Func03()//发送数据请求
    {
        F03_requests++;

        int frameSize = 8;
        F03_NumberofRegisters = (int)(F03_values.Length);
        if (F03_NumberofRegisters < 1) F03_NumberofRegisters = 1;
        if (F03_Starting_Address < 0) F03_Starting_Address = 0;
        F03_Byte_Count = (byte)(F03_NumberofRegisters * 2);

        frame03[0] = F03_Slave_Address;
        frame03[1] = F03_Function;
        frame03[2] = (byte)(F03_Starting_Address >> 8);
        frame03[3] = (byte)F03_Starting_Address;
        frame03[4] = (byte)(F03_NumberofRegisters >> 8);
        frame03[5] = (byte)F03_NumberofRegisters;

        int crc16 = calculateCRC(frame03, frameSize - 2);
        byte crcHi, crcLo;
        crcHi = (byte)((crc16 >> 8) & 0xFF);//循环冗余校验返回值得高8位
        crcLo = (byte)(crc16 & 0xFF);//循环冗余校验返回值得低8位
        frame03[frameSize - 2] = crcHi;
        frame03[frameSize - 1] = crcLo;
        try
        {
            sp.Write(frame03, 0, frameSize);//使用缓冲区中的数据将指定数量的字节写入串行端口
        }
        catch (System.Exception ex)
        {
            print(ex);
            F03_exception_errors++;
            return;
        }

        sp.BaseStream.Flush();

    }


    void RecvFunc03()//串口数据接收
    {
        Array.Clear(F03_values, 0, F03_values.Length);//F03_values----最终拿来存放寄存器的值
        int Size = 0;
        byte tempB = 0;
        int maxrev = 5 + F03_Byte_Count;//【设备地址】【03】【字节数】+ 寄存器数据字节数（一共8个寄存器，每个寄存器16位（2个字节），一共16个字节）+【CRC 低字节】【CRC 高字节】
        try
        {
            while (tempB != F03_Slave_Address)
            {
                tempB = (byte)sp.ReadByte();//从串口中读取一个字节数据
            }

            while (Size < maxrev)
            {
                frame03[Size] = (byte)(tempB);//将读取到的数据帧存入frame03数组
                if (Size == (maxrev - 1)) break;
                tempB = (byte)sp.ReadByte();
                Size++; 
            }

        }
        catch (System.Exception ex)
        {
            F03_exception_errors++;
            return;
        }


        if (Size == (maxrev - 1))
        {
            if (frame03[0] == F03_Slave_Address && frame03[1] == F03_Function)
            {
                //print(frame03[0]);
                int crc16 = calculateCRC(frame03, Size - 1);//用接收到的数据帧进行循环冗余校验，，Size---是接收到的整个数据帧的大小
                int received_crc = ((frame03[Size - 1] << 8) | frame03[Size]);
                if (crc16 == received_crc && frame03[2] == F03_Byte_Count)//若校验成功
                {
                    print("CRC校验成功");
                    F03_valuesEnable = true;
                    int index = 3;
                    for (int i = 0; i < F03_NumberofRegisters; i++)
                    {
                        /*int isNegative = frame03[index] & 0x80;
                        if (isNegative != 0)//不等于0，说明此寄存器的数据为负数，将其转换为十进制负数
                        {
                            int temp = (int)((frame03[index] << 8) | frame03[index + 1]) - 1;
                            temp = temp ^ 0xFFFF;
                            F03_values[i] = -temp;
                        }
                        else
                        {
                            F03_values[i] = (int)((frame03[index] << 8) | frame03[index + 1]);//提取数据帧中的寄存器数据，保存到F03_values数组，一个数组元素保存一个寄存器数据
                        }*/
                        F03_values[i] = (int)((frame03[index] << 8) | frame03[index + 1]);//提取数据帧中的寄存器数据，保存到F03_values数组，一个数组元素保存一个寄存器数据
                        print(F03_values[i]);
                        index += 2;
                    }
                    F03_successful_requests++;
                    return;
                }
                else
                {
                    print("CRC校验失败");
                    F03_valuesEnable = false;
                }
            }
        }

        F03_failed_requests++;
    }



    void Modbus_Update()
    {
        switch (state)
        {
            case 0:
                state = 1;
                break;

            case 1:
                state = 2;
                break;

            case 2:
                Func03();//发请求
                state = 3;
                break;
            case 3:
                RecvFunc03();
                state = 0;
                break;
        }
    }


}
