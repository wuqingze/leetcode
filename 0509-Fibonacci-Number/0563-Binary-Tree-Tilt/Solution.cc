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
struct Node:TreeNode{
    int s1;
    int s2;
};

class Solution {
public:
    Node* f(TreeNode* root){
        auto node = new Node();
        if(root == nullptr){
            node->s1 = 0;
            node->s2 = 0;
        }else if(root->left == nullptr and root->right == nullptr){
            node->s1 = root->val;
            node->s2 = 0;
        }else{
            auto node1 = f(root->left);
            auto node2 = f(root->right);
            node->s1 = node1->s1+node2->s1+root->val;
            node->s2 = abs(node1->s1-node2->s1)+node1->s2+node2->s2;
        }
        return node;
    }
    
    int findTilt(TreeNode* root) {
        auto node = f(root);
        return node->s2;        
    }
};
