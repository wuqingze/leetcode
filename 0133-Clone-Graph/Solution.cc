#include <vector>
#include <unordered_map>
#include <queue>
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

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        auto *result = new Node(node->val, {});
        unordered_map<Node*, Node*> copies;
        copies[node] = result;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            auto *cur = q.front();
            q.pop();
            for(auto *neighbor:cur->neighbors){
                if(copies.find(neighbor) == copies.end()){
                    copies[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return result;
    }
};

int main(){
    cout<<"hello world"<<endl;
    return 0;
}
