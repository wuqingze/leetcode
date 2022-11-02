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
    void up(vector<ListNode*> &l){
        int n = l.size();
        int i=n-1;
        int p;
        while(i!=0){
            p = (i-1)/2;
            if(l[p]->val > l[i]->val){
                swap(l[i], l[p]);
                i =  p;
            }else break;
        }
    }

    void down(vector<ListNode*> &heap){
        int n = heap.size();
        int i=0;
        int l,r,t;
        while(i<n){
            l = 2*i+1;
            r = 2*i+2;
            t = i;
            if(l<n and heap[l]->val < heap[t]->val) t = l;
            if(r<n and heap[r]->val < heap[t]->val) t = r;

            if(t == i) break;
            else{
                swap(heap[t], heap[i]);
                i = t;
            }
        }
    }

    ListNode* top(vector<ListNode*>& heap){
        if(heap.size() == 0) return nullptr;
        else return heap[0];
    }

    bool empty(vector<ListNode*> &heap){
        return heap.size() == 0;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head;
        ListNode* cur = head;
        vector<ListNode*> heap;
        int n = lists.size();
        for(int i=0;i<n;i++){
            if(lists[i] != nullptr){
                heap.push_back(lists[i]);
                up(heap);
            }
        }
        while(not empty(heap)){
            auto node = top(heap);
            cur->next = node;
            cur = cur->next;
            if(node->next == nullptr){
                heap[0] = heap[heap.size()-1];
                heap.pop_back();
                down(heap);
            }else{
                heap[0] = node->next;
                down(heap);
            }
        }
        return head->next;
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
