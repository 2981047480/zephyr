fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","r+")#Open the file in mode 'r+'
a=fp.readlines()#Read datiles from the file to a list
fp.close()#Close the file
fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","w+")#Open the file in mode 'w+'
print(a[0])#Print the first line of the file
print(a[1])#Print the second line of the file
len=len(a)#calculator the lenth of the list(a)
#for i in a:
#    
#    for j in
fp.close()

