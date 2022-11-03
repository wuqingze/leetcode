#include <iostream>
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddhead = new ListNode();
        ListNode* evenhead = new ListNode();
        ListNode* oddcur = nullptr;
        ListNode* evencur = nullptr;

        ListNode* cur = head;
        while(cur){
            if(cur->val % 2 == 0){
                if(evencur == nullptr){
                    evenhead->next = cur;
                    evencur = cur;
                }else{
                    evencur->next = cur;
                    evencur = cur;
                }
            }else{
                if(oddcur == nullptr){
                    oddhead->next = cur;
                    oddcur = cur;
                }else{
                    oddcur->next = cur;
                    oddcur = cur;
                }
            }
            cur = cur->next;
        }
        if(evencur) evencur->next = nullptr;
        if(oddcur == nullptr) oddhead->next = evencur;
        else{
            oddcur->next = evenhead->next;
        }
        return oddhead->next;
    }
};

int main(){
    Solution solution;
    //ListNode* head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    //
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);
    
    auto ret = solution.oddEvenList(head);

    while(ret){
        cout<<ret->val<<",";
        ret = ret->next;
    }
    cout<<endl;
    cout<<"-----------"<<endl;
    return 0;
}
