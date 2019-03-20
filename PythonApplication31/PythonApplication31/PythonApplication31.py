def q(n):
    if(n==1):
        s=1
    else:
        s=n*q(n-1)
    return s
print(q(5))