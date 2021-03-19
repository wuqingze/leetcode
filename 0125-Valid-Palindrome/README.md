### 127. Word Ladder
<span style="color:red">Hard</span> &nbsp; **favorable:** 4778 &nbsp; **unfavorable:** 1403

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `$s_i$` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return the **number of words** in the **shortest transformation sequence** from `beginWord` to `endWord`, or `0` if no such sequence exists.

#### Example 1:
```
<span style="font-weight:bold">Input:</span> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
<span style="font-weight:bold">Output:</span> 5
<span style="font-weight:bold">Explanation:</span> One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", 
which is 5 words long.
```

#### Example 2:
```
<span style="font-weight:bold">Input:</span> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
<span style="font-weight:bold">Output:</span> 0
<span style="font-weight:bold">Explanation:</span> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

#### Constraints:
- 1 <= beginWord.length <= 10
- endWord.length == beginWord.length
- 1 <= wordList.length <= 5000
- wordList[i].length == beginWord.length
- beginWord, endWord, and wordList[i] consist of lowercase English letters.
- beginWord != endWord
- All the words in wordList are unique.
