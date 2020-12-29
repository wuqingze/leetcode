# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        if not head.next or k == 1:
            return head

        t = []
        cur = head
        while cur:
            t.append(cur)
            cur = cur.next
        n = len(t)

        for i in range(0,(n//k)*k,k):
            j = i+k-1
            if i >= k:
                t[i-k].next = t[j]
            while j>i:
                t[j].next = t[j-1]
                j -= 1
        
        if n%k == 0:
            if n-2*k>-1:
                t[n-2*k].next = t[n-1]
            t[n-k].next = None
        else:
            if (n//k)*k-k > -1:
                t[(n//k)*k-k].next = t[(n//k)*k]
        if k<=n:
            return t[k-1]
        else:
            return t[0]

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
# head.next.next.next.next = ListNode(5)
k = 2
s =Solution()
s.reverseKGroup(head,k)