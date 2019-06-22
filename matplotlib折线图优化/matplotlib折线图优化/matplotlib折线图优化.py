import matplotlib.pyplot as a

x=[1,2,3,4]
y=[1.2,2.5,4.5,7.3]

a.plot(x,y,color="r",linestyle="--",marker="*",linewidth=1.0)

a.savefig("a.png",dpi=120)

a.show()