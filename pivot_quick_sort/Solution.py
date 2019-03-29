def xx(nums,l,r):
    i = l
    j = r
    pivot = nums[r]
    while i<j:
        if nums[i] > pivot:
            swap(nums,i,j)
            i += 1
            j -= 1
        else:
            i += 1

def swap(nums,i,j):
    t = nums[i]
    nums[i] = nums[j]
    nums[j] = t

a = [4.5]
xx(a,0,0)
print(a)
