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
class BSTIterator {
public:
    stack<TreeNode*> stck;
    
    BSTIterator(TreeNode* root) {
        auto ptr = root;
        while(ptr){
            stck.push(ptr);
            ptr = ptr->left;
        }
    }
    
    int next() {
        auto node = stck.top();
        stck.pop();
        int result = node->val;
        if(node->right){
            node = node->right;
            while(node){
                stck.push(node);
                node = node->left;
            }
        }        
        return result;
    }
    
    bool hasNext() {
        return not stck.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
