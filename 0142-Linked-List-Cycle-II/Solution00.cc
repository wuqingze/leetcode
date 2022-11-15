#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr or head== nullptr) return nullptr;

        ListNode* A;
        ListNode* B;
        ListNode* C;
        A = B = C = head;
        while(A and B){
            A = A->next;
            B = B->next?B->next->next:nullptr;
            if(A == B){
                while(1){
                    if(A == C) return C;
                    A = A->next;
                    C = C->next;
                }
            }
        }
        return nullptr;
    }
};

int main(){
    Solution solution;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; 

    auto ret = solution.detectCycle(head);
    if(ret){
        printf("the entry of cycle is %d\n", ret->val);
    }else{
        printf("cycle does'nt exist\n");
    }
    return 0;
}
