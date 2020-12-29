# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def xx(self,root,level,result,left):
        if root == None:
            return 
        else:
            if level < len(result):
                result[level].append(root.val)
            else:
                result.append([root.val])
            if left:
                self.xx(root.left,level+1,result,not left)
                self.xx(root.right,level+1,result,not left)
            else:
                self.xx(root.right,level+1,result,not left)
                self.xx(root.left,level+1,result,not left)
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        # self.xx(root,0,result,False)
        # return result
        
        level = 0
        cur = root
        cur.level = level
        q = [cur]
        i = 0
        n = 1
        while cur != None:
            if cur.level < len(result):
                result[level].append(cur.val)
            else:
                result.append([cur.val])
            i += 1
            if cur.left != None:
                cur.left.level = cur.level + 1
                q.append(cur.left)
                n += 1
            if cur.right != None:
                cur.right.level = cur.level + 1
                q.append(cur.right)
                n += 1
            cur =  q[i] if i<n else None
        # for i in range(len(result)):
        #     if n % 2 == 1:
        #         result[i] = result[i][::-1]
        return result

root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.right = TreeNode(7)
root.right.left = TreeNode(15)

s = Solution()
print(s.zigzagLevelOrder(root))
        