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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stck;
        auto cur = root;
        TreeNode* pre = nullptr;
        vector<int> ret;
        while(cur or not stck.empty()){
            while(cur){
                stck.push(cur);
                cur = cur->left;
            }
            if(not stck.empty()){
                cur = stck.top();
                stck.pop();
                if(not cur->right or pre == cur->right){
                    ret.push_back(cur->val);
                    pre = cur;
                    cur = nullptr;
                }else{
                    stck.push(cur);
                    cur = cur->right;
                }
            }
        }
        return ret;
    }
};
