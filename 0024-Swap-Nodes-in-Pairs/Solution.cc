#include <iostream>
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
    static ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* preHead = new ListNode(0, head);
        ListNode* pre = preHead;
        ListNode* cur=head, *nxt=head->next;
        
        while(cur && nxt){
            cur->next = nxt->next;
            nxt->next = cur;
            pre->next = nxt;
            pre = cur;
            cur = cur->next;
            nxt = cur?cur->next:nullptr;
        }
        
        return preHead->next;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int n;
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        while(is>>n){
            pre->next = new ListNode(n);
            pre = pre->next;
        }
        auto *ret = Solution::swapPairs(preHead->next);
        cout<<line<<endl;;
        while(ret){ cout<<ret->val<<" "; ret=ret->next;}
        cout<<endl;
    }
    return 0;
}
