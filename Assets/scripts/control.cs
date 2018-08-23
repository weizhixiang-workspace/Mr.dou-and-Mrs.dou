using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class control : MonoBehaviour {

    public GameObject SerialportObject;

    public serialport script;

    public int fan_speed = 0;

    private short modbus_read;
    private short modbus_write;

    private bool conn = false;
    public Transform target;
    public float speed;
    private float org_x;//origin x at any start time
    private float org_y;//origin y at any start time
    private float org_z;//origin z at any start time
    private bool sMove = false;
    private Vector3 endpos;
    private float process = 0;

    void OnGUI()
    {
        switch (script.Connection_Status)
        {
            case 0:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Common Error");
                break;
            case 1:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Closing port, because it was already open!");
                break;
            case 2:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Port Opened!");
                break;
            case 3:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Port is already open");
                break;
            case 4:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Port == null");
                break;
            case 5:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Not Existing " + script.PortName.ToString() + " , Please ReStart");
                break;
            case 6:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : Exception Errors");
                break;
            case 100:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : OK");
                conn = true;
                break;
            case 101:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : OK");
                conn = true;
                break;
            case 102:
                GUI.Label(new Rect(10, 40, Screen.width, 25), "Connection Status : OK");
                conn = true;
                break;
        }

        GUI.Label(new Rect(10, 100, 250, 25), "Modbus 40002 => Fan Speed : " + modbus_read.ToString());
    }


    void Start()
    {
        script = SerialportObject.GetComponent<serialport>();
    }

    void FixedUpdate()
    {

        //if (script.F03_values.Length > 1){
        //	modbus_write = (short) script.F03_values [0];
        //	modbus_read = (short) script.F03_values [1];
        //	fan_speed = modbus_read;
        //}
        GameObject PB;
        // PB = GameObject.Find("Cube");
        PB = GameObject.FindGameObjectWithTag("Player");
       
        if (script.F03_values[4] > 50000)
        {
            print("script.F03_values[4] : --------" + script.F03_values[4]);
            //print (script.F03_values[1]);
            //modbus_write = (short) script.F03_values [0];
            modbus_read = (short)script.F03_values[0];
            //fan_speed = modbus_read;
            print("right");
            PB.transform.Translate(0, 0, Time.deltaTime);
        }
        else
        {
            if (script.F03_values[1] > 50000)
            {
                //print (script.F03_values[1]);
                //modbus_write = (short) script.F03_values [0];
                modbus_read = (short)script.F03_values[1];
                //fan_speed = modbus_read;
                print("left");
                PB.transform.Translate(0, 0, -Time.deltaTime);
            }
            else
            {
                if (script.F03_values[2] > 50000)
                {
                    //print (script.F03_values[1]);
                    //modbus_write = (short) script.F03_values [0];
                    modbus_read = (short)script.F03_values[2];
                    //fan_speed = modbus_read;
                    print("up");
                    PB.transform.Translate(0, Time.deltaTime, 0);
                }
                else
                {
                    if (script.F03_values[3] > 50000)
                    {
                        //print (script.F03_values[1]);
                        //modbus_write = (short) script.F03_values [0];
                        modbus_read = (short)script.F03_values[3];
                        //fan_speed = modbus_read;
                        print("down");
                        PB.transform.Translate(0, -Time.deltaTime, 0);
                    }
                }
            }
        }
        //if (sMove)
        //{
        //	print ("2");
        //	process += Time.deltaTime * 2;
        //	if (process < 1)
        //		transform.position = Vector3.Lerp(transform.position, endpos, process);
        //	else
        //	{
        //		sMove = false;
        //	}
        //}

    }
    public void x_increase()
    {
        if (!sMove)
        {
            print("1");
            //endpos = new Vector3(transform.position.x - 1, transform.position.y, transform.position.z);
            GameObject PB;
            PB = GameObject.Find("Cube");
            PB.transform.Translate(0, 0, 10 * Time.deltaTime);
            //endpos = new Vector3(PB.transform.position.x - 1, PB.transform.position.y, PB.transform.position.z);
            //endpos = new Vector3(1, 0, 0);
            process = 0;
            sMove = true;
            //print("OK");
        }
    }
    public void x_decrease()
    {
        if (!sMove)
        {
            endpos = new Vector3(transform.position.x + 1, transform.position.y, transform.position.z);
            process = 0;
            sMove = true;
        }
    }
    public void y_increase()
    {
        if (!sMove)
        {
            endpos = new Vector3(transform.position.x, transform.position.y + 1, transform.position.z);
            process = 0;
            sMove = true;
        }
    }
    public void y_decrease()
    {
        if (!sMove)
        {
            endpos = new Vector3(transform.position.x, transform.position.y - 1, transform.position.z);
            process = 0;
            sMove = true;
        }
    }
    public void z_increase()
    {
        if (!sMove)
        {
            endpos = new Vector3(transform.position.x, transform.position.y, transform.position.z - 1);
            process = 0;
            sMove = true;
        }
    }
    public void z_decrease()
    {
        if (!sMove)
        {
            endpos = new Vector3(transform.position.x, transform.position.y, transform.position.z + 1);
            process = 0;
            sMove = true;
        }
    }
    public void x_rotate_increase()
    {
        transform.Rotate(-15, 0, 0);
    }
    public void x_rotate_decrease()
    {
        transform.Rotate(15, 0, 0);
    }
    public void y_rotate_increase()
    {
        transform.Rotate(0, -15, 0);
    }
    public void y_rotate_decrease()
    {
        transform.Rotate(0, 15, 0);
    }
    public void z_rotate_increase()
    {
        transform.Rotate(0, 0, -15);
    }
    public void z_rotate_decrease()
    {
        transform.Rotate(0, 0, 15);
    }


}
