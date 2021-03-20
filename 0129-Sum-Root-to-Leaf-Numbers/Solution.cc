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
    void f(string pre, TreeNode* root, int &ret){
        if(not root) return;
        char t = '0'+root->val;
        if(not root->left and not root->right){
            ret += atoi(
                (pre+t).c_str());
            return;
        }
            
        if(root->left)
            f(pre+t, root->left, ret);
        if(root->right)
            f(pre+t, root->right, ret);
    }
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        string pre = "";
        f(pre, root, ret);
        return ret;
    }
};
