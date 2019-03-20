a = int(input('输入四位数字:'))
aa = [a % 10, a % 100 // 10, a % 1000 // 100, a // 1000]

for i in range(4):
    aa[i] += 5
    aa[i] %= 10
for i in range(2):
    aa[i], aa[3 - i] = aa[3 - i], aa[i]
for i in range(3, -1, -1):
    print(str(aa[i]), end="")

