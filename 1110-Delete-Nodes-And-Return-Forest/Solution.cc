/**
* Definition for a binary tree node.
* struct TreeNode {
* int val;
* TreeNode *left;
* TreeNode *right;
* TreeNode() : val(0), left(nullptr), right(nullptr) {}
* TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
* TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    //用map存储tree中的所有节点及其对应的父节点，如果某个节点为要
    //删除的节点，那么从map中找到该节点，父亲节点指向该节点的分支
    //置为空，从map中删除该节点。最后map从剩余的节点为最终结果
 }
}
