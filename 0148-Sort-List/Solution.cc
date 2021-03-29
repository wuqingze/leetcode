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
    ListNode* sortList(ListNode* head) {
        if(not head) return nullptr;
        auto ptr = head;
        vector<ListNode*> l;
        while(ptr){
            l.push_back(ptr);
            ptr = ptr->next;
        }
        sort(l.begin(), l.end(), [](ListNode* o1, ListNode* o2){
            return o1->val < o2->val;
        });
        int n = l.size();
        for(int i=0;i<n-1;i++){
            l[i]->next = l[i+1];
        }
        l[n-1]->next = nullptr;
        return l[0];
    }
};
