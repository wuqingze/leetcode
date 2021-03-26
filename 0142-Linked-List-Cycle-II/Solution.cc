/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<void*> ts;
        auto ptr = head;
        while(ptr){
            if(ts.find(ptr) != ts.end()){
                return ptr;
            }
            ts.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};
