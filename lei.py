class A:
	def a(self):
		print('a function')
	def b(self):
		self.a()
		print('b function')

if __name__ == '__main__':
	a = A()
	a.b()