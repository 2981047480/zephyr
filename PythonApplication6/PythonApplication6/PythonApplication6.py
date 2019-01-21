def q(n):
    if(n==1):
        return 0
    if(n==2):
        return 1
    else:
        return q(n-1)+q(n-2)
n=int(input('请输入需要得到的项数:\n'))
for n in range(1,n+1):
    print(q(n))