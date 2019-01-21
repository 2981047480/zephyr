a=int(input('请输入第一个数\n'))
b=int(input('请输入第二个数\n'))
c=int(input('请输入第三个数\n'))
for i in range(1,3):
    if(a>b):
        d=a
        a=b
        b=d
    if(a>c):
        d=a
        a=c
        c=d
    if(b>c):
        d=b
        b=c
        c=d
print(a,b,c)