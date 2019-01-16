def insertion_sort(nums):
    '''
    就像从nums中抽牌一样，每次抽一张到手上，手上的牌是已经排序过的。
    新抽出来的牌key=nums[i]，与手上已有的牌nums[0,i-1]逐个对比，有比它大的，就把它往前移动一位。
    n^2
    '''
    for i in range (len(nums)):
        key = nums[i]
        j = i-1
        while j >= 0 and nums[j] > key:
            nums[j+1] = nums[j]
            j = j-1
        nums[j+1] = key
    return nums
nums = [5,2,4,6,1,3]
res = insertion_sort(nums)
print (res)
