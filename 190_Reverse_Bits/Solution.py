class Solution:
    def self.__init__(self):
        self.s = {}
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        if self.s.get(n) == None:
            t = bin(n)[2:]
            n = len(t)
            if n < 32:
                t = '0'*(34-n)+t[2:]
            tt = t[::-1]
            self.s[n] = int(tt,2)
            return self.s[n]
        else:
            return self.s[n]

