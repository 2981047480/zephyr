li=[3,2,5,7,8,1,5]

m=li[0]
a=li.index(max(li))
li[0]=li[a]
li[a]=m

n=li[len(li)-1]
b=li.index(min(li))
li[len(li)-1]=li[b]
li[b]=n

print(li)