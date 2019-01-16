def quick_sort(A, p, r):
    def partition(A, p, r):
        x = A[r]
        i = p-1
        for j in range(p,r):
            if A[j]<=x:
                i = i + 1
                A[i], A[j] = A[j], A[i]
        A[i+1], A[r] = A[r], A[i+1]
        return i+1
    if p < r:
        pp = partition(A, p, r)
        quick_sort(A, p, pp-1)
        quick_sort(A, pp+1, r)
    return 
  


nums = [5,6,4,6,12,34,7,8,4,4,2,5]

quick_sort(nums,0,11)

print(nums)