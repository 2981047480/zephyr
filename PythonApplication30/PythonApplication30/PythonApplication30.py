def q(a_list):
    if(len(a_list)!=len(set(a_list))):
        return False
    else:
        return True
a=input('请输入列表\n')
a_list=a.split(" ")
print(q(a_list))