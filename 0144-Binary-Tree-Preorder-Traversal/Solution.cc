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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stck;
        stck.push(root);
        vector<int> ret;
        while(not stck.empty()){
            auto node = stck.top();
            stck.pop();
            while(node){
                ret.push_back(node->val);
                if(node->right) stck.push(node->right);
                node = node->left;
            }
        }
        return ret;
    }
};
