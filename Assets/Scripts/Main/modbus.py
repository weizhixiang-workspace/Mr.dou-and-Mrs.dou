# -*- coding: utf-8 -*-
"""Module importation"""
import serial
import matplotlib.pyplot as plt

"""Opening of the serial port"""
try:
    arduino = serial.Serial(port='COM4', baudrate=9600, timeout=1)
except:
    print('Please check the port')

while True:
    try:
        str_data = str(arduino.readline())
        print(str_data)
        # time.sleep(1)
    except arduino.SerialTimeoutException:
        print('Data could not be read')
        # time.sleep(1)


# import serial
# import mmap
# import contextlib
# import modbus_tk.defines as cst
# from modbus_tk import modbus_rtu
#
# # 寄存器数组reg_data->生成指令
# def get_command(reg_data):
#     command = ''
#     for i in range(len(reg_data)):
#         if 24000 < reg_data[i] < 32000:
#             command += '1'  # 1为弯曲指令
#         elif 34000 < reg_data[i] < 42000:
#             command += '2'  # 2为伸直指令
#         else:
#             command += '0'  # 0为啥也不做指令
#     return command
#
#
# def read_serial_data(serial):
#     """
#     Given a pyserial object (serial). Outputs a list of lines read in
#     from the serial port
#     """
#     serial.flushInput()
#     serial_data = []
#     # while readings_left and not timeout_reached:
#     serial_line = serial.readline()
#     print(serial_line)
#     serial_data.append(serial_line)
#     return serial_data
#
# if __name__ == '__main__':
#         # try:
#         #     println("Trying...")
#         #     arduino = serial.Serial("COM4", timeout=1)
#         # except:
#         #     print("Failed to connect to Arduino!")
#         #
#         # data = read_serial_data(arduino)
#         try:
#             arduino = serial.Serial(port="COM4", baudrate=9600, timeout=1)
#         except:
#             print('Please check the port')
#
#         while True:
#             row_data = arduino.readline()
#             print(row_data)
#             str_data = str(row_data)
#             print("str_data: " + str_data)
#             clean_data = str_data[2:]
#             print("clean_data: " + clean_data[:-5])
#             seg_data = clean_data.split(" ")
            # draw_curve(seg_data)
    # ser1 = serial.Serial('COM4', 9600)
    # PORT = "COM4"
    # master = modbus_rtu.RtuMaster(serial.Serial(port=PORT, baudrate=9600, bytesize=8, parity='N', stopbits=1, xonxoff=0))
    # master.set_timeout(1)
    # master.set_verbose(True)
    # with contextlib.closing(mmap.mmap(-1, 1024, tagname='ShareMemory', access=mmap.ACCESS_WRITE)) as m:
    #     with open("D:/Projects/UNITY_PROJECT/Mr.dou-and-Mrs.dou/Assets/Doc/serialportData.txt", "w") as f:
    #         while True:
    #             try:
    #                 # 读取寄存器的值
    #                 data = read_serial_data(arduino)
    #             except:
    #                 # 若读取数据失败则向映射内存中写入8个0
    #                 m.seek(0)
    #                 m.write(('00000000').encode('utf-8'))
    #                 m.flush()
    #                 continue
    #             # 成功读取数据,向映射内存中写入转换后的指令
    #             m.seek(0)
    #             m.write((get_command(data)).encode('utf-8'))
    #             m.flush()
    #             # 向txt文件中写入某一时刻读取的数据（换行）
    #             str_data = ''
    #             for i in range(len(data)):
    #                 str_data += str(data[i]) + ' '
    #             f.write(str_data + '\n')
    #




