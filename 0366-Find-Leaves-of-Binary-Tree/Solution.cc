#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){val = v;}
};

class Solution {
public:
    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr and root->right == nullptr) return 1;
        return max(depth(root->left),depth(root->right))+1;
    }

    int f(TreeNode* node, TreeNode* p, vector<vector<int>>& res) {
        if(node == nullptr) return 0;

        int t1 = f(node->left, node, res);
        int t2 = f(node->right, node, res);

        res[max(t1,t2)].push_back(node->val);
        node->left = nullptr;
        node->right = nullptr;
        if(p != nullptr){
            if(p->left == node) p->left == nullptr;
            else p->right == nullptr;
        }
        delete node;
        return max(t1, t2)+1;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        int dpth = depth(root);
        vector<vector<int>> res = vector<vector<int>>(dpth, vector<int>());
        f(root, nullptr, res);
        return res;
    }
};

int main(){
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution;
    auto res = solution.findLeaves(root);
    cout<<"[";
    for(auto l:res){
        cout<<"[";
        for(auto i:l) cout<<i<<",";
        cout<<"],";
    }
    return 0;
}
