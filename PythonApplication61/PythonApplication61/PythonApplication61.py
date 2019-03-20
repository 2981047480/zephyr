a,b,c=map(int,input('请输入\n').split())
for i in range(3):
        if(a>b):
            d=a
            a=b
            b=d
        if(b>c):
            d=b
            b=c
            c=d
        if(a>c):
            d=a
            a=c
            c=d
print(a,b,c)
