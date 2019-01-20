a=int(input('请输入年份\n'))
b=int(input('请输入月份\n'))
c=int(input('请输入日\n'))
month1=[0,31,60,91,121,152,182,213,244,274,305,335,366]
month2=[0,31,59,90,120,151,181,212,243,273,304,334,365]
if(a%4==0 and a%100!=0):
    day=month1[b-1]+c
if(a%400==0):
    day=month1[b-1]+c
else:
    day=month2[b-1]+c
print('这是第',format(day),'天')