#n=input('please enter:\n')
#a,b,c=n.split('')
a,b,c=input('please enter:\n').split(' ')
if(b=='+'):
    print(int(a)+int(c))
elif(b=='-'):
    print(int(a)-int(c))
elif(b=='*'):
    print(int(a)*int(c))
elif(b=='/'):
    print(int(a)/int(c))