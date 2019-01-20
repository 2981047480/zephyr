count=0
for i in range(1,4):
    for j in range(1,4):
        for k in range(1,4):
            if(i!=j and i!=k and j!=k):
                count=count+1
                a=i*100+j*10+k
                print(a)
print(count)