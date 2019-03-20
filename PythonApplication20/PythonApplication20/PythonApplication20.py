n=int(input('请输入n\n'))
if(n%3==0 and n%5!=0):
    print('Fizz')
if(n%3!=0 and n%5==0):
    print('Buzz')
if(n%3==0 and n%5==0):
    print('FizzBuzz')