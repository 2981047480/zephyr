count=0
i=int(input('请输入n\n'))
for i in range(1,i):
    for j in range(2,i):
        if(i%j==0):
            break
    else:
        count=count+1
print(count)