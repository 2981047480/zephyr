a=int(input('请输入利润\n'))
b=0
int(b)
if(a<=10):
    b=0.1*a
if(10<a and a<=20):
    b=1+0.075*(a-10)
if(a>20 and a<=40):
    b=1+0.75+0.05*(a-20)
if(a>40 and a<=60):
    b=1+0.75+0.5+0.03*(a-40)
if(a>60 and a<=100):
    b=1+0.75+0.5+0.3+0.015*(a-60)
if(a>100):
    b=1+0.75+0.5+0.3+0.15+0.1*(a-100)
print('奖金为',format(b),'万元')
