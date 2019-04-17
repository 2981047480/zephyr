import re

fp=open('C:\\Users\\dell\\Desktop\\任务与资料\\数据.txt','r+',encoding='UTF-8')#打开处理前的数据
a=fp.read()
a.replace(',',' ')
fp1=open('C:\\Users\\dell\\Desktop\\任务与资料\\数据1.txt','w+',encoding='UTF-8')#新建文件存储处理后的数据
a.replace('>',' ')
a=re.sub(u">","",a)#去除‘>’
a=re.sub(u",","",a)#去除‘,’
a=re.sub(u"16:23:02 2019","",a)#去除文件中的这一列
a=re.sub(u"租房网","",a)
a=re.sub(u"租房","",a)#去除‘租房’和‘租房网’字样
a=re.sub(u"(季付价)","",a)
a=re.sub(u"(半年付价)","",a)#去除‘(半年付价)’和'（季付价）'字样
a=a.replace('(','').replace(')','')#上一步不知道为什么没有清理完，再清理一下
a=re.sub(u"基本信息 发布：","",a)
a=re.sub(u"公寓 独立卫生间 近地铁 押一付一","",a)#去掉这一列
a=re.sub(u"精装","",a)#去掉这几列
a=re.sub(u"随时看房","",a)#去掉这个关键字
a=re.sub(u"合租","",a)
a=re.sub(u"整租","",a)
a=re.sub(u"租赁方式未知","",a)
a=re.sub(u"房屋信息","",a)
a=re.sub(u"新上","",a)
a=re.sub(u"近地铁","",a)
a=re.sub(u"数据","",a)
a=re.sub(u"入住：","",a)
a=re.sub(u"租期：","",a)
a=re.sub(u"看房：需提前预约","",a)
a=re.sub(u"看房：随时可看","",a)
a=re.sub(u"楼层：","",a)
a=re.sub(u"电梯：","",a)
a=re.sub(u"车位：","",a)
a=re.sub(u"用水：","",a)
a=re.sub(u"用电：","",a)
a=re.sub(u"燃气：","",a)
a=re.sub(u"采暖：","",a)
a=re.sub(u"end","",a)#去掉这些字样
a=re.sub(u"None","NULL",a)#把'None'换成'NULL'
#a=re.sub(u"地址和交通","",a)
a=re.sub(u"    "," ",a)
a=re.sub(u"   "," ",a)
a=re.sub(u"   "," ",a)
a=re.sub(u"     "," ",a)
a=re.sub(u"    "," ",a)
a=re.sub(u"   "," ",a)
a=re.sub(u"   "," ",a)
a=re.sub(u"  "," ",a)#把所有间距都变成一个空格
fp1.write(a)
fp.close()
fp1.close()
fp2=open('C:\\Users\\dell\\Desktop\\任务与资料\\数据1.txt','r+',encoding='UTF-8')
b=fp2.readlines()
long=len(b)