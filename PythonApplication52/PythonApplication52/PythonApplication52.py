def a(i):
    e=i//1000000
    if(i//100000!=0):
        d=i//100000-e*10
    else:
        d=0
    if(i//10000!=0):
        c=i//10000-e*100-d*10
    else:
        c=0
    if(i//1000!=0):
        b=i//1000-e*1000-d*100-c*10
    else:
        b=0
    print(b,c,d,e)
f=int(input('请输入数字\n'))
a(f)