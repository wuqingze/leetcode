### 144. Binary Tree Preorder Traversal
**Medium** **favorable:** 2157 **unfavorable:** 87

Given the root of a binary tree, return the preorder traversal of its nodes' values.

#### Example 1:
![](imgs/inorder_1.jpg)
```
Input: root = [1,null,2,3]
Output: [1,2,3]
```

#### Example 2:
```
Input: root = []
Output: []
```

#### Example 3:
```
Input: root = [1]
Output: [1]
```

#### Example 4:
![](imgs/inorder_4.jpg)
```
Input: root = [1,2]
Output: [1,2]
```

#### Example 5:
![](imgs/inorder_5.jpg)
```
Input: root = [1,null,2]
Output: [1,2]
```

#### Constraints:
- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100
 
**Follow up:** Recursive solution is trivial, could you do it iteratively?
