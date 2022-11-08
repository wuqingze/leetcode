#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

class Solution {
public:
    string format(string k, string l, string r){
        return "{k:"+k+",l:"+l+",r:"+r+"}";
    }

    string f(TreeNode* node, set<string> &cnt, map<string, TreeNode*>& res){
        if(not node) return "{}";
        string key = format(to_string(node->val), 
                f(node->left, cnt, res),
                f(node->right,cnt, res));

        if(cnt.count(key)) res[key] = node;
        else cnt.insert(key);
        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, TreeNode*> res;
        set<string> cnt;
        f(root, cnt, res);
        vector<TreeNode*> ret;
        for( auto itr=res.begin();itr!=res.end();itr++){
            ret.push_back(itr->second);
        }
        return ret; 
    }
};

void traverse(TreeNode* node){
    if(not node) return;
    cout<<node->val<<",";
    traverse(node->left);
    traverse(node->right);
}

int main(){
/**
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
**/
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);


    Solution solution;
    auto ret = solution.findDuplicateSubtrees(root);
    for(auto node: ret){
        traverse(node);
        cout<<endl;
    }
    return 0;
}
