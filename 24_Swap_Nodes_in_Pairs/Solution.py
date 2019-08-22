# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        if head.next == None:
            return head
        
        
        l = []
        t = head
        while t:
            l.append(t)
            t = t.next
            
        n = len(l)
        
        for i in range(0,n,2):
            if i+1<n:
                l[i+1].next = l[i]
                if i>1:
                    l[i-2].next = l[i+1]
            else:
                l[i-2].next = l[i]
        if n %2 == 0:
            l[-2].next = None
        else:
            l[-1].next = None
                
        return l[1]

head = ListNode(1)
head.next = ListNode(2)
# head.next.next = ListNode(3)
# head.next.next.next = ListNode(4)

s = Solution()
t = s.swapPairs(head)
print(t.val,t.next.val,t.next.next.val,t.next.next.next.val)