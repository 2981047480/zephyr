#150 11000 百分之86.22
#coding="utf-8"
import pandas as pd
import matplotlib.pyplot as plt
#columns=["城市","区","方位","房屋名","大小","租赁方式","朝向","月租","计费方式","几室","几厅","几卫","入住","租期","看房","所在楼层","总楼高","电梯","车位","用水","用电","燃气","供暖"]
houses=pd.read_csv("a.csv",encoding="gbk")
print(houses.head(5))

fig=plt.figure()
ax1=fig.add_subplot()
#ax2=fig.add_subplot(2,1,2)
houses.plot("area","money",kind="scatter",ax=ax1)
#houses.plot("money","mpg",kind='scatter',ax=ax2)
plt.show()

