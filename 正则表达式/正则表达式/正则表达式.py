import re

a='C45Java452C#1431254 Python|Javascript'
r=re.findall(".*?1",a)
print(r)
#.*?为贪婪匹配

a='C45Java452C#1431254 Python|Javascript'
r=re.findall("[3]",a)
print(r)
#匹配字符集

r=re.findall("[34]",a)
print(r)
#这个会匹配出所有3和4（单个字符）

r=re.findall("[a-z]",a)
print(r)
#返回含有a-z的字符（单个字符）

r=re.findall("[a-zA-z]+",a)
print(r)
#带着+会返回更长的字符串,+是一个或多个字符

r=re.findall("[a-zA-Z]+",a)
print(r)
#这个a和A的顺序可以反过来

r=re.findall("[a-zA-Z]{4}",a)
print(r)
#后面的花括号代表的是字符个数，默认贪婪匹配，即匹配更多

r=re.findall("[a-zA-z]{4-6}",a)
print(r)
#匹配4或6个，但尽量每个字符串会匹配更多字符

b="PythonPython2Python3Pythonn"

r=re.findall("Python\d",b)
print(r)
#泛匹配

r=re.findall("(Python)(\d)",b)
print(r)
#精确匹配，匹配结果会把python和数字分开，匹配的是括号中的东西



