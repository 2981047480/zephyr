n=int(input('请输入要分解的数字\n'))
print(n,"=",end=" ")
while n!=1:
    for i in range(2,n+1):
        if(n%i==0):
            n=n/i
            if(n!=1):
                print(i,"*",end=" ")
            else:
                print(i)
print( )