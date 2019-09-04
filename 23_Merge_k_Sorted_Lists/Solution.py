# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        if len(lists) == 0:
            return None

        temp = lists
        while len(temp) > 1:
            t = []
            n = len(temp)
            for i in range(0,n,2):
                if i < n-1:
                    t.append(self.merge2Lists(temp[i],temp[i+1]))
                else:
                    t.append(temp[i])
            temp = t
        return temp[0]

    def merge2Lists(self,l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        if l2 == None:
            return l1

        cur1 = l1
        cur2 = l2
        l = None
        cur = None
        if cur1.val < cur2.val:
            l = cur1
            cur = cur1
            cur1 = cur1.next
        else:
            l = cur2
            cur = cur2
            cur2 = cur2.next

        while cur1 or cur2:
            if not cur1:
                cur.next = cur2
                break
            elif not cur2:
                cur.next = cur1
                break
            else:
                if cur1.val < cur2.val:
                    cur.next = cur1
                    cur = cur1
                    cur1 = cur1.next
                else:
                    cur.next = cur2
                    cur = cur2
                    cur2 = cur2.next
        return l

# l1 = ListNode(1)
# l1.next = ListNode(4)
# l1.next.next = ListNode(5)
# l2 = ListNode(1)
# l2.next = ListNode(3)
# l2.next.next = ListNode(4)
# l3 = ListNode(2)
# l3.next = ListNode(6)

l1 = ListNode(-2)
l2 = None
l3 = ListNode(-1)
s = Solution()
print(s.mergeKLists([l1,l2,l3]))