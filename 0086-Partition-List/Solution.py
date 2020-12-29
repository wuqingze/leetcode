# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
        def partition(self, head, x):
            if head == None or head.next == None:
                return head

            leHead = None
            gHead = None
            le = None
            g = None
            cur = head
            while cur:
                if cur.val < x:
                    if leHead == None:
                        le = cur
                        leHead = cur
                    else:
                        le.next = cur
                        le = cur
                else:
                    if gHead == None:
                        g = cur
                        gHead = cur
                    else:
                        g.next = cur
                        g = cur
                cur = cur.next

            if g:
                g.next = None 
            if le:
                le.next = gHead
                return leHead
            else:
                return gHead
head = ListNode(1)
head.next = ListNode(4)
head.next.next = ListNode(3)
head.next.next.next = ListNode(2)
head.next.next.next.next = ListNode(5)
head.next.next.next.next.next = ListNode(2)
s = Solution()
h = s.partition(head,3)
while h:
    print(h.val, end=',')
    h = h.next
