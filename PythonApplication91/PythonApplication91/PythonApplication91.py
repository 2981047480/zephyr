f=open("C:\\Users\\dell\\Desktop\\text2.txt","r+")
f1=open("C:\\Users\\dell\\Desktop\\test3.txt","w+")
st=f.read()
a_list=st.split("\n")
b_list=[[]*3]*(len(a_list))
for i in range(len(a_list)-1):
    b_list[i]=a_list[i].split(" ")
    for j in range(3):
        f1.write(b_list[i][j]+" ")
    f1.write(",")
    if (i+1)%100==0:
        f1.write("\n")
f,f1.close()
