import itertools
class Solution:
    def xx(self,b):
        m = 0
        h = 0
        mm = b[-6:]
        hh = b[0:4]
        
        for i in range(len(mm)):
            m += mm[i]*(2**(6-i-1))
            if m > 59:
                return None
            
        for i in range(len(hh)):
            h += hh[i]*(2**(4-i-1))
            if h > 11:
                return None
        h = str(int(h))
        if m >= 10:
            m = str(m)
        else:
            m = '0'+str(m)
        return h+':'+m
    
    def isSwap(self,a, length, index):
        for i in range(index+1,length):
            if a[index] == a[i]:
                return False
        return True

    def permutation(self,array,i,n,result):
        if i == n-1:
            result.append(list(array))
        else:
            for j in range(i,n):
                if self.isSwap(array,n,j):
                    t = array[i]
                    array[i] = array[j]
                    array[j] = t
                    self.permutation(array,i+1,n,result)
                    t = array[i]
                    array[i] = array[j]
                    array[j] = t
                    
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        t =  []
        self.permutation([1]*num+[0]*(10-num),0,10,t)
        ans = []
        for i in range(len(t)):
            a = self.xx(t[i])
            if a != None:
                ans.append(a)
                
        return ans


s = Solution()
s.xx([1,0,1,1,1,0,0,0,0,0])
# print(s.readBinaryWatch(4))
# result = []
# s.permutation([1,1,1,1,0,0,0,0,0,0],0,10,result)
# for i in range(len(result)):
#     if result[i] == [1,0,1,1,1,0,0,0,0,0]:
#         print(True)
