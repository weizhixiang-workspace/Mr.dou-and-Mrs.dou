import serial
import mmap
import contextlib
import modbus_tk.defines as cst
from modbus_tk import modbus_rtu


def get_command(reg_data):
    command = ''
    for i in range(len(reg_data)):
        if 24000 < reg_data[i] < 32000:
            command += '1'  # 1为弯曲指令
        elif 34000 < reg_data[i] < 42000:
            command += '2'  # 2为伸直指令
        else:
            command += '0'  # 0为啥也不做指令
    return command


if __name__ == '__main__':
    PORT = "COM4"
    master = modbus_rtu.RtuMaster(serial.Serial(port=PORT, baudrate=9600, bytesize=8, parity='N', stopbits=1, xonxoff=0))
    master.set_timeout(1)
    master.set_verbose(True)
    with contextlib.closing(mmap.mmap(-1, 1024, tagname='ShareMemory', access=mmap.ACCESS_WRITE)) as m:
        with open("D:/Projects/UNITY_PROJECT/Mr.dou-and-Mrs.dou/Assets/Doc/serialportData.txt", "w") as f:
            while True:
                try:
                    data = master.execute(1, cst.READ_HOLDING_REGISTERS, 0, 8)
                except:
                    m.seek(0)
                    m.write(('00000000').encode('utf-8'))
                    m.flush()
                    continue
                m.seek(0)
                m.write((get_command(data)).encode('utf-8'))
                m.flush()
                str_data = ''
                for i in range(len(data)):
                    str_data += str(data[i]) + ' '
                f.write(str_data + '\n')





