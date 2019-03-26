fp=open("C:\\Users\\dell\\Desktop\\text.txt","r+")
a=fp.readline()
print(a[0])
fp1=open("C:\\Users\\dell\\Desktop\\text1.txt","w+")
while(a!=''):
    long=len(a)
    if(long<35):
        pass
    else:
        #print(a)
        fp1.write(a)
    a=fp.readline()
    #step 2 is half