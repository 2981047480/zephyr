def q(n):
    if(n<=0):
        return False
    while(n>1):
        if(n%3!=0):
            return False
        n=n/3
    return True
n=int(input('请输入要判断的数\n'))
print(q(n))