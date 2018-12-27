class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        s = set()
        for i in range(len(emails)):
            t = emails[i].split('@')
            local = t[0]
            domain = t[1]
            tt = ''
            for j in range(len(local)):
                if local[j] == '+':
                    break
                elif local[j] != '.':
                    tt += local[j]
            ttt = ''
            tj = domain.split('.com')[0]
            for j in range(0,len(tj)):
                if tj[j] == '+':
                    break
                ttt += tj[j]
            s.add(tt+'@'+ttt+'.com')
        print(s)
        return len(s)

s = Solution()
print(s.numUniqueEmails(["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]))