a = 1
b = 1
c = 1
for a in range(-100,101):
	for b in range(-100,101):
		for c in range (-100,101):
			if a+b != 0 and a+c != 0 and b+c != 0:
				if abs((a/(b+c))+(c/(a+b))+(b/(a+c))-4) == 0: #< 0.00000000000000001:
					print('a:',a)
					print('b:',b)
					print('c:',c)