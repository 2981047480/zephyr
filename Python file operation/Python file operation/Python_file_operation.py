fp=open("C:\\Users\\dell\\Desktop\\text.txt","r+")
a=fp.readline()
a_list=a.split(',')
b=[]
b.append(a_list)
j=0
while a!='':
    a=fp.readline()
    a_list=a.split(',')
    b.append(a_list)
long=len(b)
print(b[0][1])
for i in range(1,long-1):
    if(b[i][1]!=b[i-1][1]):
        j=j+1
