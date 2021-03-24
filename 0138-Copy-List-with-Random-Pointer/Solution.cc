#include <map>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> nodeL;
        map<void*, int> tmap;
        auto ptr = head;
        while(ptr){
            nodeL.push_back(ptr);
            tmap[ptr] = nodeL.size()-1;
            ptr = ptr->next;
        }

        int n = nodeL.size();
        vector<Node*> copyL(nodeL.size());
        for(int i=0;i<n;i++){
            copyL[i] = new Node(nodeL[i]->val);
            if(i != 0) copyL[i-1]->next = copyL[i];
        }

        vector<int> indexL(n);
        for(int i=0;i<n;i++){
            if(nodeL[i]->random){
                indexL[i] = tmap[nodeL[i]->random];
            }else{
                indexL[i] = -1;
            }
        }
        
        for(int i=0;i<n;i++){
            copyL[i]->random = indexL[i] == -1?nullptr:copyL[indexL[i]];
        }
        return copyL.size()==0?NULL:copyL[0];
    }
};

int main(){
    return 0;
}
