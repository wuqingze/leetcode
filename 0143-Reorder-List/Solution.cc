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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        auto ptr = head;
        while(ptr){
            arr.push_back(ptr);
            ptr = ptr->next;
        }
        int n = arr.size();
        int i=0, j = n-1;
        while(i<j){
            arr[j]->next = arr[i]->next;
            arr[i]->next = arr[j];
            i += 1;
            j -= 1;
        }
        arr[i]->next = nullptr;
    }
};
