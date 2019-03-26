fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","r+")#Open the file in mode 'r+'
a=fp.readlines()#Read datiles from the file to a list
fp.close()#Close the file
fp=open("C:\\Users\\dell\\Desktop\\样本01.txt","w+")#Open the file in mode 'w+'
print(a[0])#Print the first line of the file
print(a[1])#Print the second line of the file
if(a[0]==a[1]):
    a.pop(1)
    fp.writelines(a)#Write the list into the file
fp.close()
