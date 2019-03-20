def sum(nums, target):
    for a in range(len(nums)-1):
            for b in range(a + 1, len(nums)):
                if nums[a] + nums[b] == target:
                    return [a,b]
a=int(input('请输入目标数字\n'))
l=[1,2,3,4,5]
print(sum(l,a))