### 115. Distinct Subsequences
<span style="color:red">Hard</span> &nbsp; **favorable:** 1811 &nbsp; **unfavorable:** 63

Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

A string's **subsequence** is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

It is guaranteed the answer fits on a 32-bit signed integer.

#### Example 1:
```
<span style="font-weight:bold">Input:</span> s = "rabbbit", t = "rabbit"
<span style="font-weight:bold">Output:</span> 3
<span style="font-weight:bold">Explanation:</span>
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
``` 

#### Example 2:
```
<span style="font-weight:bold">Input:</span> s = "babgbag", t = "bag"
<span style="font-weight:bold">Output:</span> 5
<span style="font-weight:bold">Explanation:</span>
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
``` 

#### Constraints:
- 0 <= s.length, t.length <= 1000
- s and t consist of English letters.
