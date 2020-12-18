#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*> &dp){
        if(node == nullptr) return nullptr;
        auto *result = new Node(node->val);
        dp.insert({node, result});
        for(auto n:node->neighbors){
            if(dp.find(n) == dp.end()) result->neighbors.push_back(dfs(n, dp));
            else result->neighbors.push_back(dp[n]);
        }
        return result;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> dp;
        return dfs(node, dp);
    }
};

int main(){
    cout<<"hello world"<<endl;
    return 0;
}
