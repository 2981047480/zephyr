a=int(input('请输入数字\n'))
b=a//10000
c=(a-b*10000)//1000
d=(a-b*10000-c*1000)//100
e=(a-b*10000-c*1000-d*100)//10
f=a-b*10000-c*1000-d*100-e*10
if(b!=0):
    print('它是5位数\n')
    print(f,e,d,c,b)
elif(c!=0):
    print('它是4位数\n')
    print(f,e,d,c)
elif(d!=0):
    print('它是3位数\n')
    print(f,e,d)
elif(e!=0):
    print('它是2位数\n')
    print(f,e)
elif(f!=0):
    print('它是1位数\n')
    print(f)