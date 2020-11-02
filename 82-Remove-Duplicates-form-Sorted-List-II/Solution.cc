#include <iostream>
#include <sstream>
#include <vector>

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
    static ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        ListNode* cur = head;
        bool b=true;
        while(cur){
            bool t = (!cur->next) || (cur->val != cur->next->val);
            if(cur->next){
                if(b && cur->val != cur->next->val) {pre->next = cur; pre = cur;}
            }else{
                if(b) {pre->next= cur; pre = cur;}
            }
            ListNode* temp= cur->next;
            cur->next = nullptr;
            cur = temp;
            b = t;
        }
        
        return preHead->next;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        int n;
        while(is>>n){
            pre->next = new ListNode(n);
            pre = pre->next;
        }
        auto ret = Solution::deleteDuplicates(preHead->next);
        cout<<line<<endl;
        while(ret){
            cout<<ret->val<<" ";
            ret = ret->next;;
        }
        cout<<endl;
    }
    return 0;
}
