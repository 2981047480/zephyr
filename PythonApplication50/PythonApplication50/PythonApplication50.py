def rotate(nums, k):
    length=len(nums)
    i=k%length
    nums[:] = nums[-i:] + nums[:-i]
    return nums
a_list=[1,2,3,4,5]
k=int(input('请输入移动位数\n'))
print(rotate(a_list,k))