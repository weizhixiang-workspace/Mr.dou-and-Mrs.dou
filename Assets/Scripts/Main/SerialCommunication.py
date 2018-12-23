# -*- coding: utf-8 -*-
"""Module importation"""
import contextlib
import mmap

import serial
import time
# def get_command(reg_data):
#     command = ''
#     for i in range(1, len(reg_data)):
#         reg_data_i = float(reg_data[i])
#         if 18 < reg_data_i < 20:
#             command += '1'  # mid
#         elif 20 < reg_data_i < 30:
#             command += '2'  # high
#         else:
#             command += '0'  # nothing
#     return command

# i = 0
# while True:
#     time.sleep(1)
#     row_data = arduino.readline()
#     str_data = str(row_data)
#     # print("str_data: "+str_data)
#     clean_data = str_data[2:]
#     clean_data = clean_data[:-5]
#     # print("clean_data: " + clean_data)
#     seg_data = clean_data.split(" ")
#     # print(type(seg_data))
#     # print(seg_data)
#     data = list(map(float, seg_data))
#     print(data)

if __name__ == '__main__':
    """Opening of the serial port"""
    try:
        arduino = serial.Serial(port="COM4", baudrate=9600, timeout=1)
    except Exception as ex:
        print('Please check the port')
        print(ex)
    fileName = "D:/Projects/UNITY_PROJECT/EE5003_Update_20181101/MscProj_20181025/Assets/Doc/serialportData.txt"
    with contextlib.closing(mmap.mmap(-1, 1024, tagname='ShareMemory', access=mmap.ACCESS_WRITE)) as m:
        while True:
            # time.sleep(0.1)
            row_data = arduino.readline()
            if row_data.__len__() == 0:
                continue
            str_data = str(row_data)
            # print(str_data[2:6])

            # # print("str_data: "+str_data)
            # clean_data = str_data[2:]
            # clean_data = clean_data[:-5]
            clean_data = str_data[2:7]  # 增加一个命令用来弯手腕:str_data[6]
            clean_data = '0' + clean_data
            print("clean Data: " + clean_data)

            # # seg_data = clean_data.split(" ")
            # # print(type(seg_data))
            # # print(seg_data)
            # # data = list(map(float, seg_data))
            # # print(data)

            m.seek(0)
            m.write(clean_data.encode('utf-8'))
            m.flush()
            f = open(fileName, "w")
            f.write(clean_data + '\n')
            f.flush()
            f.close()

