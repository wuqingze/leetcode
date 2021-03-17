### 123. Best Time to Buy and Sell Stock III
<span style="color:red">Hard</span> &nbsp; **favorable:** 3335 &nbsp; **unfavorable:** 86

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i^{th}$ day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#### Example 1:
```
<span style="font-weight:bold">Input:</span> prices = [3,3,5,0,0,3,1,4]
<span style="font-weight:bold">Output:</span> 6
<span style="font-weight:bold">Explanation:</span> Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

#### Example 2:
```
<span style="font-weight:bold">Input:</span> prices = [1,2,3,4,5]
<span style="font-weight:bold">Output:</span> 4
<span style="font-weight:bold">Explanation:</span> Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4. Note that you 
cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions 
at the same time. You must sell before buying again.
```

#### Example 3:
```
<span style="font-weight:bold">Input:</span> prices = [7,6,4,3,1]
<span style="font-weight:bold">Output:</span> 0
<span style="font-weight:bold">Explanation:</span> In this case, no transaction is done, i.e. max profit = 0.
```

#### Example 4:
```
<span style="font-weight:bold">Input:</span> prices = [1]
<span style="font-weight:bold">Output:</span> 0
```
 
#### Constraints:
- 1 <= prices.length <= 105
- 0 <= prices[i] <= 105
