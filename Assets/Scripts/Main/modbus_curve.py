import serial
import mmap
import contextlib
import matplotlib.pyplot as plt
import modbus_tk.defines as cst
from modbus_tk import modbus_rtu


def draw_curve(point):
    global counter
    counter += 1
    obsX.append(counter)
    obsY1.append(point[0])
    obsY2.append(point[1])
    obsY3.append(point[2])
    obsY4.append(point[3])
    if obsX.__len__() > 400:
        obsX.pop(0)
        obsY1.pop(0)
        obsY2.pop(0)
        obsY3.pop(0)
        obsY4.pop(0)
    line1.set_xdata(obsX)
    line1.set_ydata(obsY1)
    ax1.set_xlim([counter - xlim_offset_lower, counter + xlim_offset_higher])
    ax1.set_ylim([ylim_lower, ylim_higher])
    line2.set_xdata(obsX)
    line2.set_ydata(obsY2)
    ax2.set_xlim([counter - xlim_offset_lower, counter + xlim_offset_higher])
    ax2.set_ylim([ylim_lower, ylim_higher])
    line3.set_xdata(obsX)
    line3.set_ydata(obsY3)
    ax3.set_xlim([counter - xlim_offset_lower, counter + xlim_offset_higher])
    ax3.set_ylim([ylim_lower, ylim_higher])
    line4.set_xdata(obsX)
    line4.set_ydata(obsY4)
    ax4.set_xlim([counter - xlim_offset_lower, counter + xlim_offset_higher])
    ax4.set_ylim([ylim_lower, ylim_higher])
    plt.pause(0.001)


fig = plt.figure(figsize=(20, 20))
ax1 = fig.add_subplot(4, 1, 1)
ax2 = fig.add_subplot(4, 1, 2)
ax3 = fig.add_subplot(4, 1, 3)
ax4 = fig.add_subplot(4, 1, 4)
fig.tight_layout(pad=8, w_pad=1, h_pad=8)  # 调整子图之间的间隔
ax1.set_ylabel('voltage')
ax1.set_title('Data of Register 1')
ax2.set_ylabel('voltage')
ax2.set_title('Data of Register 2')
ax3.set_ylabel('voltage')
ax3.set_title('Data of Register 3')
ax4.set_xlabel('The sampling sequence number')
ax4.set_ylabel('voltage')
ax4.set_title('Data of Register 4')
line1 = ax1.plot([0, 0], [4000, 4000], '-g', marker='')[0]
line2 = ax2.plot([0, 0], [4000, 4000], '-g', marker='')[0]
line3 = ax3.plot([0, 0], [4000, 4000], '-g', marker='')[0]
line4 = ax4.plot([0, 0], [4000, 4000], '-g', marker='')[0]
plt.ion()
counter = 0
ylim_lower = 22000
ylim_higher = 45000
xlim_offset_lower = 500
xlim_offset_higher = 100
obsX = []
obsY1 = []
obsY2 = []
obsY3 = []
obsY4 = []


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
                # 从串口通信中获取数据
                try:
                    data = master.execute(1, cst.READ_HOLDING_REGISTERS, 0, 8)
                except:
                    m.seek(0)
                    m.write(('00000000').encode('utf-8'))
                    m.flush()
                    continue
                # 写入共享内存
                m.seek(0)
                m.write((get_command(data)).encode('utf-8'))
                m.flush()
                # 将串口数据保存到文本文档中
                str_data = ''
                for i in range(len(data)):
                    str_data += str(data[i]) + ' '
                f.write(str_data + '\n')
                # 将串口数据以曲线形式呈现
                draw_curve(data)


