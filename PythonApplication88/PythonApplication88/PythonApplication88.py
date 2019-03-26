fp=open("C:\\Users\\dell\\Desktop\\样本02.txt","r+")
a=fp.readline()
print(a[0])
list(a)
fp1=open("C:\\Users\\dell\\Desktop\\text.txt","w+")
while(a!=''):
    list(a)
    long=len(a)
    for i in (0,long-1):
        if(a[i]=='?' or a[i]=='&' or a[i]=='*'):
            a.pop(i)
        else:
            #print(a)
            pass
    fp1.write(a)
    a=fp.readline()
    #step 2 is half