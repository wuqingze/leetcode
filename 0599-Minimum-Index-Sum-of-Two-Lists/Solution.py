class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        ans = []
        n1 = len(list1)
        n2 = len(list2)
        m1 = {}
        mn = 0x7fffffff
        jj = {}
        for i in range(n1):
            m1[list1[i]] = i
        for i in range(n2):
            if m1.get(list2[i]) != None:
                tt = min(mn,abs(m1[list2[i]] + i))
                if tt == mn:
                    ans.append(list2[i])
                else:
                    mn = tt
                    ans = [list2[i]]
        return ans

s = Solution()
list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
list2 = ["KFC","Shogun","Burger King"]
print(s.findRestaurant(list1,list2))