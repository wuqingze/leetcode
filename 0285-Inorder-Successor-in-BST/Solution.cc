#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    TreeNode(int val_):val(val_){}
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
public:
    TreeNode* f(vector<TreeNode*> &l, TreeNode* root, int val){
        if(not root){
            return l.size() == 0?nullptr:l[l.size()-1];
        }

        if(root->val == val){
            auto node = root->right;
            while(node and node->left){
                node = node->left;
            }
            if(not node){
                return l.size() == 0?nullptr:l[l.size()-1];
            }else{
                return node;
            }
        }else if(root->val < val){
            return f(l, root->right, val);
        }else{
            l.push_back(root);
            return f(l, root->left, val);
        }
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> l;
        return f(l, root, p->val);
    }
};

int main(int argc, char* argv[]){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    TreeNode* p = new TreeNode(atoi(argv[1]));
    Solution solution;
    auto res = solution.inorderSuccessor(root, p);
    if(res){
        cout<<res->val<<endl;
    }else{
        cout<<"null"<<endl;
    }
    return 0;
}
