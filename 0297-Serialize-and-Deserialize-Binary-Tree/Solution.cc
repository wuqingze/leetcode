/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node{
    TreeNode* node;
    int left = -1;
    int right = -1;
    Node(TreeNode* node_):node(node_){}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(not root) return "0|";
        vector<Node*> l;
        l.push_back(new Node(root));
        int i=0;
        while(i<l.size()){
            if(l[i]->node->left){
                l[i]->left = l.size();
                l.push_back(new Node(l[i]->node->left));
            }
            if(l[i]->node->right){
                l[i]->right = l.size();
                l.push_back(new Node(l[i]->node->right));
            }
            i += 1;
        }
        int n = l.size();
        string ret = to_string(n)+"|";
        for(auto ptr: l){
            ret += to_string(ptr->node->val)+","+to_string(ptr->left)+","+to_string(ptr->right)+"|";
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = atoi(data.substr(0, data.find('|', 0)).c_str());
        if(n == 0) return nullptr;
        vector<TreeNode*> l(n);
        auto start = data.find('|',0)+1;
        for(int i=0;i<n;i++){
            int val = atoi(data.substr(start, data.find(',', start)-start).c_str());
            l[i] = new TreeNode(val);
            start = data.find('|', start)+1;
        }
        start = data.find('|', 0)+1;
        for(int i=0;i<n;i++){
            int left, right;
            start = data.find(',', start)+1;
            auto end = data.find(',', start);
            left = atoi(data.substr(start, end-start).c_str());
            start = end +1;
            end = data.find('|', start);
            right = atoi(data.substr(start, end-start).c_str());
            if(left != -1){
                l[i]->left = l[left];
            }
            if(right != -1){
                l[i]->right = l[right];
            }
            start = end + 1;
        }
        return l[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
