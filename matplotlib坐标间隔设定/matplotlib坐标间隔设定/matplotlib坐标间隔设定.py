import matplotlib.pyplot as plt
import numpy as np

x=np.arange(-2*np.pi,2*np.pi,0.02)
y=np.sin(x)

plt.axis([-10,10,-2,2])

plt.xticks([i*np.pi/2 for i in range(-4,5)],[str(i*5)+"$\pi$" for i in range(-4,5)])

plt.yticks([i*0.5 for i in range(-4,5)])
#这里的xticks和yticks用来设定坐标间隔

plt.xlabel("x")
plt.ylabel("y")
#xlabel和ylabel用来给x轴和y轴设置标题

plt.plot(x,y,color="DarkBlue",linestyle="-",linewidth=1)

plt.savefig("test.png")

plt.show()