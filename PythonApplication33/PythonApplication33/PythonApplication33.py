def q(n):
    if(n==1):
        n=10
    else:
        n=q(n-1)+2
    return n
print(q(5))