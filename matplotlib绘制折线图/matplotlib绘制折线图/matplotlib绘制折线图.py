import matplotlib.pyplot as plt

x=[1,2,3,4]
y=[1.2,2.5,4.5,7.3]

#plot函数作图
plt.plot(x,y)

#将当前的figure对象保存成图像文件
plt.savefig("test.png",dpi=120)

#show函数展示出这个图，如果没有这行代码，则程序完成绘图，但看不到
plt.show()
