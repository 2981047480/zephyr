import pandas as pd
pd.DataFrame({'Yes':[50,21],'No':[131,2]})
print(pd.DataFrame({'Yes':[50,21],'No':[131,2]}))
#这么做最终得到一个表格
pd.DataFrame({'Bob':['I liked it.','It was awful.'],'Sue':['Pretty good.','Bland.']})
print(pd.DataFrame({'Bob':['I liked it.','It was awful.'],'Sue':['Pretty good.','Bland.']}))
#得到的同样是一个表格
pd.DataFrame({'Bob':['I liked it.','It was awful.'],'Sue':['Pretty good.','Bland.']},index=['Product A','Product B'])
print(pd.DataFrame({'Bob':['I liked it.','It was awful.'],'Sue':['Pretty good.','Bland.']},index=['Product A','Product B']))
#这里的index用来更换表格左边的项
pd.Series([1,2,3,4,5])
print(pd.Series([1,2,3,4,5]))
#用来直接创建一个两列的表格，左面默认为0~某个值，右边默认为这个series中的值，打印出的表格下面还有dtype：int64的字样，这个不晓得是干啥的
pd.Series([30,35,40],index=['2015 Sales','2016 Sales','2017 Sales'],name='Product A')
print(pd.Series([30,35,40],index=['2015 Sales','2016 Sales','2017 Sales'],name='Product A'))
#这里的index同样也是用来改变最左边的那一列的值，不过在dtype之前多了‘Name:Product A’的字样
a=pd.read_csv("F:\\任务与资料\\supplier_data.csv")
#可以用pd.read_csv来读csv文件
print(a.shape)
#百度了一下，这个shape函数是用来计算矩阵的维数的，这里应该是用来计算a的维数的
print(a.head)
#head函数的作用是从上至下地打印元素，放在这里就是从上往下打印a中的元素
print('\n')
print(a.head(2))
#另外，参考网上的做法，还可以给后面添加参数来使它打印出你想要的前几行
print('\n')
print(a.head())
#这么调用的话，得到的是前五行的数据
b=pd.read_csv("F:\\任务与资料\\supplier_data.csv",index_col=0)
print(b.head)
#这么读的话，可以隐藏前面的第一列的0~某个数
b.head().to_csv("F:\\任务与资料\\first.csv")
#在这里尝试过b.head，不带括号的话会报错，同时，这么打开的话相当于用“w”的方法打开这个文件
           