a_list=[1,2,3,4,5,6,7,8,9]
n=int(input('请输入该数\n'))
for i in range(len(a_list)):
    if i!=len(a_list)-1 and i != 0:
        if a_list[i]<n<a_list[i + 1]:
            a_list.insert(i+1,n)
    elif i == 0:
        if n < a_list[i]:
            a_list.insert(i,n)
    else:
        a_list.append(n)
print(a_list,"\n")
