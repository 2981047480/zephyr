n=int(input('请输入n\n'))
a=int(input('请输入a\n'))
sum=0
for n in range(1,n+1):
    b=(10**n-1)*a
    c=int(b/9)
    sum=sum+c
print(sum)