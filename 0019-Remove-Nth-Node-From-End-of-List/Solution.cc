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
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preHead = new ListNode();
        preHead->next = head;
        ListNode* cur = head, *pre=preHead;

        int c=0;
        while(cur){
            c+=1;
            if(c>n){
                pre = pre->next;
            }
            cur = cur->next;
        }
        pre->next = pre->next?pre->next->next:nullptr;
        return preHead->next;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int nn;
        is>>nn;
        int n;
        ListNode* pre = new ListNode();
        ListNode* cur=pre;
        while(is>>n){
            cur->next = new ListNode(n);
            cur = cur->next;
        }
        ListNode *ret= Solution::removeNthFromEnd(pre->next, nn);
        cout<<line<<endl;
        while(ret){
            cout<<ret->val<<" ";
            ret = ret->next;
        }
        cout<<endl;
    }

    return 0;
}
