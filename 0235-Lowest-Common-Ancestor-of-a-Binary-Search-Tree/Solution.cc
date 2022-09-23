/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val < p->val and root->val<q->val){
            return f(root->right, p, q);
        }
        if((root->val>=p->val and root->val <= q->val) or (root->val >=q->val and root->val <= p->val)){
            return root;
        }
        if(root->val > p->val and root->val > q->val){
            return f(root->left, p, q);
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p, q);
    }
};
