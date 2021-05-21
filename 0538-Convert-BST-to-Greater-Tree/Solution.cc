#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void f(TreeNode* root, vector<TreeNode*> &l){
        if(not root) return;
        f(root->left, l);
        l.push_back(root);
        f(root->right, l);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> l;
        auto res = root;
        f(root, l);
        int n = l.size();
        for(int i=n-2;i>=0;i--){
            l[i]->val += l[i+1]->val;
        }
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    Solution solution;
    auto res = solution.convertBST(root);
    vector<TreeNode*> l;
    l.push_back(res);
    int i=0;
    while(i<l.size()){
        auto t  = l[i++];
        cout<<t->val<<" ";
        if(t->left) l.push_back(t->left);
        if(t->right) l.push_back(t->right);
    }
    return 0;
}
