class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left 
        self.right = right
        self.next = next

class Solution:

    def connect(self, root):

        if root == None:
            return root

        levelArray = [root]
        n = 1
        while n > 0:
            levelArray.append(None)
            t = []
            for i in range(n):
                if levelArray[i].left:
                    t.append(levelArray[i].left)
                if levelArray[i].right:
                    t.append(levelArray[i].right)
                levelArray[i].next = levelArray[i+1]
            levelArray = t
            n = len(levelArray)
        return root

def horizonList(root):
    if root == None:
        return
    print(root.val, end='')
    horizonList(root.next)

s = Solution()
root = Node(1, None, None, None)
root.left = Node(2, None, None, None)
root.right = Node(3, None, None, None)
root.left.left = Node(4, None, None, None)
root.left.right = Node(5, None, None, None)
root.right.right = Node(7, None, None, None)
s.connect(root)
horizonList(root)



