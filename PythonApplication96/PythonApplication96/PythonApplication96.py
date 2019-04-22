#kaggle的python学习第一天的大致内容
1+2+3#这么写不能像交互式那样打印出来
hat_height_cm = 25
my_height_cm = 190
# How tall am I, in meters, when wearing my hat?
total_height_meters = hat_height_cm + my_height_cm / 100
print("Height in meters =", total_height_meters, "?")
#这里他想得到的是我的身高+帽子的高度的总和除以100，即化为米的形式，但是由于没有加括号，所以出现了错误
#执行过程为25+1.9，所以错误。其中也说明了这个是错的，并给出了正确的代码：
total_height_meters = (hat_height_cm + my_height_cm) / 100
print("Height in meters =", total_height_meters, "?")
#这次运行结果是正确的
#文中还介绍了max及min函数，如下：
print(min(1,2,3))
print(max(1,2,3))
#这次运行结果正常，均可得到正确答案
#同时文中也介绍了绝对值函数
print(-hat_height_cm)
print(abs(-hat_height_cm))
#运行结果正常，可得到答案
#同时还介绍了一些强制转换的函数（据他说是函数）
print(float(10))
print(10)
print(int(3.33))
print(int('807')+1)
#这里将10强制转换成浮点型，3.33强制转换成整形，字符串‘807’强制转换成整形并+1
#运行结果无错误