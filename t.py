
gf = open("google-top-questions.csv", "r")
tf = open("tiktok.csv", "r")
google = {}
tiktok = {}
for line in gf:
    if "leetcode.com" in line:
        arr = line.split(",")
        google[arr[0]] = arr

for line in tf:
    if "leetcode.com" in line:
        arr = line.split(",")
        tiktok[arr[0]] = arr

for k,v in google.items():
    if not k in tiktok:
        print(v[0]+","+v[1]+","+v[2],end="")
