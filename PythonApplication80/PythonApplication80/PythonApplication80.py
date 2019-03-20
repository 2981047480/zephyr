nums=[4,5,0,4,5,6,4,0,6,9,0,8,0]
j=0
n=len(nums)
for i in range(0,n-1):
    if(nums[i]==0):
        j=j+1
        del(nums[i])
for a in range(j):
        nums.append(0)
print(nums)