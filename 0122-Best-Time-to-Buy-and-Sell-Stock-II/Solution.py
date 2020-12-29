class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        i = 0
        n = len(prices)
        profit = 0
        pre = prices[0]
        for j in range(n-1):
            if prices[j] < prices[i]:
                profit += prices[j-1] - prices[i]
                i = j
        
        
        return profit
s = Solution()
print(s.maxProfit([7,1,5,3,6,4]))