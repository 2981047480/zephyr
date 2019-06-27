import matplotlib.pyplot as plt
import numpy as np

x=np.arange(-5,5,0.02)
y=np.sin(x)

plt.axis([-np.pi,np.pi,-2,2])#函数原型为plt.axis([x_min,x_max,y_min,y_max])

plt.plot(x,y,color="r",linestyle="-",linewidth=1)#x是x轴数据，y是y轴数据，linestyle为控制曲线格式的字符串，linewidth是曲线宽度

plt.savefig("test.png")

plt.show()
