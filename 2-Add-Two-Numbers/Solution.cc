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

class Solution{
    public:
        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* preNode = new ListNode(0), *ptr = preNode;
            int extra = 0;
            ListNode* result;
            while(l1 || l2 || extra){
                int temp = (l1?l1->val:0)+(l2?l2->val:0)+extra;
                ptr->next = new ListNode(temp%10);
                extra = temp / 10;
                ptr = ptr->next;
                l1 = l1?l1->next:nullptr;
                l2 = l2?l2->next:nullptr;
            }
            return preNode->next;
        }
};

int main(){
    string line;
    ListNode* preNode1 = new ListNode(0), *ptr1=preNode1;
    ListNode* preNode2 = new ListNode(0), *ptr2=preNode2;
    while(getline(cin, line)){
        if(preNode1->next == nullptr){
            istringstream str(line);
            int val;
            while(str>>val){
                ptr1->next = new ListNode(val);
                ptr1 = ptr1->next;
            }
        }else{
            istringstream str(line);
            int val;
            while(str>>val){
                ptr2->next =  new ListNode(val);
                ptr2 = ptr2->next;
            }
        }
    }
    ListNode *result = Solution::addTwoNumbers(preNode1->next, preNode2->next);
    while(result){
        cout<<result->val<<"->";
        result = result->next;
    }
    return 0;
}
