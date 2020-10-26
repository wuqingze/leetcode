/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        
        while(l1 || l2){
            ListNode* cur = l1;
            if(cur){
                if(l2){
                    if(l1->val<=l2->val){
                        l1 = l1->next;
                    }else{
                        cur = l2;
                        l2 = l2->next;
                    }
                }else{
                    l1 = l1->next;
                }
            }else{
                cur = l2;
                l2 = l2->next;
            }
            
            pre->next = cur;
            pre = pre->next;
        }
        return preHead->next;
    }
};
