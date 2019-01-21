def q(n):
    if(n<=2):
        return n
    else:
        return (q(n-1)+q(n-2))
a=int(input('请输入n\n'))
print(q(a))
