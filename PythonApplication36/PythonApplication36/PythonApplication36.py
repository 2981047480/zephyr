letter=str(input('请输入首字母\n'))
if letter.__eq__("m"):
    print("Monday")
elif letter.__eq__("w"):
    print("Wednesday")
elif letter.__eq__("f"):
    print("Friday")
elif letter.__eq__("t"):
    a=str(input('请再输入一个字母\n'))
    if a.__eq__("u"):
        print("Tuesday")
    elif a.__eq__("h"):
        print("Thursday")
    else:
        print('请检查输入是否正确\n')
elif letter.__eq__("s"):
    a=str(input('请再输入一个字母\n'))
    if a.__eq__("u"):
        print("Sunday")
    elif a.__eq__("a"):
        print("Saturday")
    else:
        print('请检查输入是否正确\n')
else:
    print('请检查输入是否正确\n')