def heap_sort(nums):
    '''
    nlogn, in_place
    '''
    def max_heapify(start, end):
        '''
        adjust
        '''
        root = start
        while True:
            child = 2*root+1
            if child>end:
                break
            if child+1 <= end and nums[child] < nums[child+1]:
                    child+=1
            if nums[root] < nums[child]:
                nums[root], nums[child] = nums[child], nums[root]
                root = child
            else:
                break

    def build_max_heap(nums):
        '''
        creat heap
        '''
        for i in range((len(nums)-2)/2, -1, -1):
            max_heapify(i, len(nums)-1)
    
    build_max_heap(nums)
    for end in range(len(nums)-1, 0, -1):
        nums[0], nums[end] = nums[end], nums[0]
        max_heapify(0, end - 1)   
    return nums
    
nums = [9,2,6,8,1,8,0,5]

print(heap_sort(nums))