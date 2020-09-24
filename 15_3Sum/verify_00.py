## 好像第一个写的程序不仅耗时，而且得到的结果要少一些
## Solution.cc能够得到正确的结果和更快的速度
f = open('tt')
s = [] 
for line in f:
    t = line.strip().split(" ")
    t = sorted(t)
    ts = str(t)
    if ts in s:
        print(ts)
    else:
##       print("--", ts)
        s.append(ts)
