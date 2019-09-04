# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        cur = head
        nxt = head.next
        while cur.next != None:
            cur.next = pre
            pre = cur
            cur = nxt
            nxt = cur.next
        cur.next = pre
        return cur

s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)
head = s.reverseList(head)
while head!= None:
    print(head.val)
    head = head.next