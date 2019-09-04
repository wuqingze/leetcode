class Solution:
    def __init__(self):
        self.result = []
    def isSwap(self,a, length, index):
        for i in range(index+1,length):
            if a[index] == a[i]:
                return False
        return True

    def permutation(self,array,i,n):
        if i == n-1:
            self.result.append(list(array))
        else:
            for j in range(i,n):
                if self.isSwap(array,n,j):
                    t = array[i]
                    array[i] = array[j]
                    array[j] = t
                    self.permutation(array,i+1,n)
                    t = array[i]
                    array[i] = array[j]
                    array[j] = t

    


s = Solution()
# s.permutation([1,1,1,1,0,0,0,0,0,0],0,10)
s.permutation([3,1,1],0,3)
print(s.result)
