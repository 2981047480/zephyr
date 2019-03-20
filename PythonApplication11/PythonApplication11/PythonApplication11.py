
def q(n):
    num=0
    int(num)
    while(n>0):
        if(n%2==1):
            num=num+1
        n=n//2
    return num
n=int(input('请输入要判断的数\n'))
print(q(n))