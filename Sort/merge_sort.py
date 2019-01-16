def merge(left, right):
  
    result = []
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    if left:
        result += left
    if right:
        result += right
    return result
    
def merge_sort(nums):
    '''
        nlogn
    '''
    if len(nums) <=1:
        return nums
    mid = len(nums)/2
    left = nums[:mid]
    right = nums[mid:]
    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)

nums = [4,7,2,9,8,0,3,6]
res = merge_sort(nums)

print (res)