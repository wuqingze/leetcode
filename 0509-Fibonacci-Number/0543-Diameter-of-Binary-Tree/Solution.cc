/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, int &ans){
        if(root == nullptr) return 0;
        if(root->left == nullptr and root->right == nullptr){
            ans = max(ans, 0);
            return 1;
        }
        int t1 = f(root->left, ans);
        int t2 = f(root->right, ans);
        ans = max(ans, t1+t2);
        return max(t1, t2)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
};
