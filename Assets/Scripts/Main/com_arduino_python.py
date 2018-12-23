# -*- coding: utf-8 -*-
"""Module importation"""
import serial
import mmap
import contextlib
"""Opening of the serial port"""
try:
    arduino = serial.Serial("/dev/ttyACM0", timeout=1)
except:
    print('Please check the port')

"""Initialising variables""" 
data = []


def clean(L):   # L is a list
    new = []  # initialising the new list
    for i in range(len(L)):
        temp = L[i][2:]
        new.append(temp[:-5])
    return new


with contextlib.closing(mmap.mmap(-1, 1024, tagname='ShareMemory', access=mmap.ACCESS_WRITE)) as m:
    with open("D:/Projects/UNITY_PROJECT/Mr.dou-and-Mrs.dou/Assets/Doc/serialportData.txt", "w") as f:
        while True:
            rawdata.append(str(arduino.readline()))
            clean_data = clean(rawdata)
            m.seek(0)
            m.write((get_command(data)).encode('utf-8'))
            m.flush()
            str_data = ''
            for i in range(len(data)):
                str_data += str(data[i]) + ' '
            f.write(str_data + '\n')

print(f.close())