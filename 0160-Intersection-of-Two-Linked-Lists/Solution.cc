#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0;
        int n = 0;
        auto a = headA;
        auto b = headB;
        while(a!=NULL) { m +=1;a=a->next;}
        while(b!=NULL) { n +=1;b=b->next;}
        a = headA;
        b = headB;
        if(m>n){
            int gap = m-n;
            while(gap-->0) a=a->next;
        }else if(m < n){
            int gap = n-m;
            while(gap-->0) b=b->next;
        }
        while(a != NULL and b != NULL){
            if(a == b) return a;
            else{
                a = a->next;
                b = b->next;
            }
        }
        return nullptr;
    }
};


int main(){
    /**
    ListNode* interset = new ListNode(8);
    interset->next = new ListNode(4);
    interset->next->next = new ListNode(5);

    ListNode* headA = new ListNode(8);
    headA->next = new ListNode(1);
    headA->next->next = interset;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = interset; 
    **/

    ListNode* interset = new ListNode(2);
    interset->next = new ListNode(4);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = interset;

    ListNode* headB = new ListNode(3);
    headB->next = interset; 

    Solution solution;
    auto ret = solution.getIntersectionNode(headA, headB);
    cout<<ret->val<<endl;
    return 0;
}
