def rotate(nums, k):
    length = len(nums)
    i = k % length
    nums[:] = nums[-i:] + nums[:-i]
a=int(input('请输入要移动的位数\n'))
li=[1,2,3,4,5,6,7]
b=a%len(li)
rotate(li,b)
print(li)