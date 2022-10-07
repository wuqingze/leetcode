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
    bool f(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr and subRoot == nullptr){
            return true;
        }else if(root == nullptr or subRoot == nullptr){
            return false;
        }else{
            return (root->val == subRoot->val) and (f(root->left, subRoot->left) and f(root->right, subRoot->right));
        }
    }
    
    bool ff(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr) return subRoot == nullptr;
        if(f(root, subRoot)) return true;
        if(ff(root->left, subRoot)) return true;
        if(ff(root->right, subRoot)) return true;
        
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return ff(root, subRoot);
    }
};
