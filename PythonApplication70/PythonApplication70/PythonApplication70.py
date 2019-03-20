a=int(input('请输入数字'))
b=a%2
sum=0
if b==0:
    for i in range(1,a+1):
        sum=sum+1/i
else:
    for i in range(1,a+1):
        sum=sum+1/i
print(sum)