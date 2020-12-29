def generateSequence():
    result = ['1']
    for i in range(1,30):
        t = result[-1]
        n = len(t)
        tt = ''
        index = 0
        while index < n:
            c = 1
            while index + 1 < n and t[index] == t[index+1]:
                c += 1
                index += 1
            tt += str(c)+t[index]            
            index += 1
        result.append(tt)
    return result

# def countAndSay(self,n):
#     s = self.generateSequence()
#     return s[n-1]

s = generateSequence()
print(s)

