class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def rotateRight(self, head, k):
        if None == head or None == head.next:
            retur head


        cnt = 0
        cur = head
        while cur:
            cnt += 1
            if cur.next == None:
                cur.next = head
                break

            cur = cur.next
        k = k % cnt
        cur = head
        i = 1 
        while i < cnt-k:
            cur = cur.next
            i += 1
        result = cur.next
        cur.next = None
        return result



