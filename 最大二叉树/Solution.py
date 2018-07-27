class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxnums(self,nums):
        index = 0
        maxnum = -99999999999999
        for i in range(len(nums)):
            if nums[i]>maxnum:
                maxnum = nums[i]
                index = i
        return [index,maxnum]
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if nums == None or len(nums) == 0:
            return None
        im = self.maxnums(nums)
        root = TreeNode(im[1])
        root.left = self.constructMaximumBinaryTree(nums[0:(im[0]-1)])
        root.right = self.constructMaximumBinaryTree(nums[(im[0]+1):])
        return root

def main():
    r = Solution().constructMaximumBinaryTree([3,2,1,6,0,5])
    print(r)

if __name__ == '__main__':
    main()