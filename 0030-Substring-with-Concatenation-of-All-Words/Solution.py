class Solution:
    def generateString(self,words,i,n,stringset):
        if i == n-1:
            s = ""
            for i in range(n):
                s += words[i]
            stringset.add(s)
            return 
        
        for j in range(i,n):
            t = words[j]
            words[j] = words[i]
            words[i] = t
            self.generateString(words,i+1,n,stringset)
            words[i] = words[j]
            words[j] = t
            
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
            if not s:
                return []
            if not words or len(words)==0:
                return []
            
            wordlen = len(words[0])
            slen = len(s)
            wordslen = len(words)
            substringlen = wordlen*wordslen
            result = []
            for i in range(slen-substringlen+1):
                if s[i:i+wordlen] in words:
                    t = words.copy()
                    j = i
                    while True:
                        if s[j:j+wordlen] in t:
                            t.remove(s[j:j+wordlen])
                            j += wordlen
                        elif len(t) == 0:
                            result.append(i)
                            break
                        else:
                            break
                            
            return result

s = Solution()
stringset = set()
s.generateString(["1","2","3",'4','5','6','7','8','9'],0,9,stringset)
print(stringset)