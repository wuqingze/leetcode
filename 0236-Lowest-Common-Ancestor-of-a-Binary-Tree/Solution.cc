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
    bool f(TreeNode* root, TreeNode* target, vector<TreeNode*> &l){
         if(root == target)  {
             l.push_back(target);
             return true;
         }
        if(root->left == nullptr and root->right == nullptr){
            return false;
        }
        
        l.push_back(root);
        if(root->left){
            bool ret = f(root->left, target, l);
            if(ret){
                return true;
            }
        }
        if(root->right){
             bool ret = f(root->right, target, l);
            if(ret){
                return true;
            }
        }
        l.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root or q == root) return root;
        
        vector<TreeNode*> l1;
        vector<TreeNode*> l2;
        
        f(root, p, l1);
        f(root, q, l2);
        int n = l1.size();
        int m = l2.size();
        for(int i=1;i<min(n, m);i++){
            if(l1[i] != l2[i]){
                return l1[i-1];
            }
        }
        return l1[min(n,m)-1];
    }
};
