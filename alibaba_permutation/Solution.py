def permutation(chars, i, n, result):
    if i == n-1:
        t = ''.join(chars)
        if t not in result:
            result.append(t)
        return

    for j in range(i,n):
        temp = chars[i]
        chars[i] = chars[j]
        chars[j] = temp
        permutation(chars, i+1, n, result)
        temp = chars[i]
        chars[i] = chars[j]
        chars[j] = temp

result  = []
chars = ['a','l','i', 'b','a','b','a']
permutation(chars,0,len(chars),result)
print(result)
print(len(result)) 
