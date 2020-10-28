#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        while(node1 || node2){
            if(node1){
                if(node2){
                    if(node1->val < node2->val){
                        pre->next = node1;
                        pre = pre->next;
                        node1 = node1->next;
                    }else{
                        pre->next = node2;
                        pre = pre->next;
                        node2 = node2->next;
                    }
                }else{
                    pre->next = node1;
                    pre = pre->next;
                    node1 = node1->next;
                }
            }else{
                pre->next = node2;
                pre = pre->next;
                node2 = node2->next;
            }
        }
        return preHead->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int c = 0;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) lists[c++] = lists[i];
        }
        if(c==0) return {};
        while(c){
            vector<ListNode*> temp;
            int i=0;
            while(i<c){
                ListNode* node = merge(lists[i], i+1<c?lists[i+1]:nullptr);
                temp.push_back(node);
                i+=2;
            }
            c /= temp.size();
            lists = temp;
        }
        return lists[0];
    }
};

int main(){
    string line;
    Solution solution;
    while(getline(cin, line)){
        vector<ListNode*> lists;
        int i=0;
        int j=0;
        int n = line.size();
        while(i+2<n){
            while(line[j] != ']') j+=1;
            int k=i+1, l=j-1;
            while(k<=l){
                if(line[k] == ',') line[k] = ' ';
                k++;
            }
            string s = line.substr(i+1, j-i-1);
            istringstream is(s);
            int n;
            ListNode *preNode = new ListNode();
            ListNode *pre = preNode;
            while(is>>n){
                pre->next = new ListNode(n);
                pre = pre->next; 
            }
            lists.push_back(preNode->next);
            i = j+2;
            j = i;
        }
        ListNode* node = solution.mergeKLists(lists);
        while(node){ cout<<node->val<<" "; node = node->next;}
        cout<<endl;
    }
    return 0;
}
