n=int(input('请输入数字\n'))
def q(n):
        bits = "{:0>32b}".format(n)
        return int(bits[::-1], 2)
print(q(n))
