str1='Central South University'
print(str1)
print(str1[0])
print(str1[8:13])
str2="I am 'python'"
print(str2)
str3="""I'm "Python"!"""
print(str3)
str4="""
I'm "Python"!
"""#用双引号或者单引号括起来的字符串可以是多行的
print(str4)#此处上下会有空格
#python中字符串中的字符不能被改变，如：
word="ABCDEFG"
#word[1]="8"    这句会报错，所以注释起来
#在python中，修改字符串只能重新赋值，python系统会自动回收不再使用的字符串，新对象会使用原来字符串的空间