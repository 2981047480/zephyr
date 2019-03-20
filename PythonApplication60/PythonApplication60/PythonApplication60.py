a=int(input('请输入要反转的数\n'))
flag=1
if a<0:
    flag=-1
    a=-a
a_list=str(a)[::-1]
a=int(a_list)
if (a> 2147483647 or a < -2147483648):
    a=0
b=a*flag
print(b)