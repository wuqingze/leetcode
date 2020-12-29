# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree(self,head,s,e):
        if s>e:
            return None
        elif s==e:
            return TreeNode(head[s])
        
        mid = (e+s)//2
        root = TreeNode(head[mid])
        root.left  = self.tree(head,s,mid-1)
        root.right = self.tree(head,mid+1,e)
        return root
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        l = []
        while head:
            l.append(head.val)
            head = head.next
        return self.tree(l,0,len(l)-1)