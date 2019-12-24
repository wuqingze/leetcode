class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head, m, n):
        if head == None or head.next == None or m>n or m<1 or m == n:
            return head
        pre = None 
        cur = head
        nxt = head.next
        preTail = None
        endHead = None
        mNode = None
        nNode = None

        c = 1 
        while cur:
            if c < m:
                pre = cur
                cur = cur.next
            elif c == m:
                preTail = pre
                mNode = cur
                pre = cur
                cur = cur.next
            elif m<c<=n:
                if c == n:
                    nNode = cur
                t = cur.next
                cur.next = pre
                pre = cur
                cur = t
            else:
                endHead = cur
                break
            c += 1
        mNode.next = endHead
        if preTail == None:
            return nNode
        else:
            preTail.next = nNode
            return head

s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
#head.next.next.next = ListNode(4)
#head.next.next.next.next = ListNode(5)
d = s.reverseBetween(head,2,3)
while d:
    print(d.val, end=',')
    d = d.next

