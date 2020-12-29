
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates

class Solution:
    def dfs(self,m,eid,em):
            if m.get(eid,None) == None:
                t = em[eid].importance
                for e in em[eid].subordinates:
                    t += self.dfs(m,e.id,em)
                m[eid] = t
            return m.get(eid)
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        
        em = {}
        for e in employees:
            em[e.id] = e            
        m = {}    
        return self.dfs(m,id,em)
        
e2  = Employee(2,3,[])        
e1 = Employee(1,2,[e2])
s = Solution()
print(s.getImportance([e1,e2],1))