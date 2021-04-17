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
    vector<int> rightSideView(TreeNode* root) {
        if(not root) return {};
        
        vector<TreeNode*> pre(100);
        vector<TreeNode*> next(100);
        vector<int> ret;
        ret.push_back(root->val);
        int cnt = 1;
        pre[0] = root;
        while(cnt != 0){
            int t = 0;
            for(int i=0;i<cnt;i++){
                if(pre[i]->left){
                    next[t++] = pre[i]->left;
                }
                if(pre[i]->right){
                    next[t++] = pre[i]->right;
                }
            }
            if(t != 0) ret.push_back(next[t-1]->val);
            swap(pre, next);
            cnt = t;
        }
        return ret;
    }
};
