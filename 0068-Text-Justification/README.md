### 68. Text Justification
<span style="color:red">Hard</span>&nbsp;&nbsp; **favorable:** 958&nbsp;&nbsp; **unfavorable:** 1907

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

**Note**:
- A word is defined as a character sequence consisting of non-space characters only.
- Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
- The input array words contains at least one word.

#### Example 1:
```
<span style="font-weight:bold">Input</span>: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
<span style="font-weight:bold">Output:</span>
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

#### Example 2:
```
<span style="font-weight:bold">Input:</span> words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
<span style="font-weight:bold">Output:</span>
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
<span style="font-weight:bold">Explanation</span>: Note that the last line is "shall be    " instead of "shall     be", because the last line
must be left-justified instead of fully-justified.  Note that the second line is also left-justified 
becase it contains only one word.
```

#### Example 3:
```
<span style="font-weight:bold">Input:</span> words = ["Science","is","what","we","understand","well","enough","to","explain","to","a",
"computer.","Art","is","everything","else","we","do"], maxWidth = 20
<span style="font-weight:bold">Output:</span>
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
``` 

#### Constraints:
- 1 <= words.length <= 300
- 1 <= words[i].length <= 20
- words[i] consists of only English letters and symbols.
- 1 <= maxWidth <= 100
- words[i].length <= maxWidth
