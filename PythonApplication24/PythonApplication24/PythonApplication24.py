a=100
s=100
count=0
for i in range(1,11):
    a=a/2
    s=s+2*a
    if(i==10):
        s=s-a
print(s)
print(a)