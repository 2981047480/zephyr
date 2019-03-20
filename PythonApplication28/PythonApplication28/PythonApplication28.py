a1=2
a2=3
b1=1
b2=2
i=int(input('请输入项数\n'))
def q(i):
    if(i==1):
        a=2
    if(i==2):
        a=3
    if(i>2):
        a=q(i-1)+q(i-2)
    int(a)
    return a
def p(i):
    if(i==1):
        b=1
    if(i==2):
        b=2
    if(i>2):
        b=p(i-1)+p(i-2)
    int(b)
    return b
sum=0
def n(i):
    n=q(i)/p(i)
    return n
for i in range(1,i):
    sum=n(i)+sum
print(sum)