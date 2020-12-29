#include <iostream>
#include <sstream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

class Solution{
    public:
        static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
            l1 = reverse(l1);
            l2 = reverse(l2);

            ListNode *preNode = new ListNode(0), *ptr = preNode;
            int extra = 0;
            while(l1 || l2 || extra){
                int sum = (l1?l1->val:0) + (l2?l2->val:0) + extra;
                ptr->next = new ListNode(sum%10);
                ptr = ptr->next;
                extra = sum / 10;
                l1 = l1?l1->next:nullptr;
                l2 = l2?l2->next:nullptr;
            }
            return reverse(preNode->next);
        };

        static ListNode *reverse(ListNode* list){
            ListNode *pre = nullptr;
            ListNode *ptr = list;
            while(ptr){
                ListNode *next = ptr->next;
                ptr->next = pre;
                pre= ptr;
                ptr = next;
            }
            return pre;
        }
};

void test00_reverse(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        ListNode *preNode = new ListNode(0), *ptr = preNode;
        int val;
        while(args>>val){
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
        cout<<"before reverse:"<<endl;
        ptr = preNode->next;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        ListNode *list = preNode->next;
        ListNode *node = Solution::reverse(list);
        cout<<endl<<"after reverse:"<<endl;
        ptr = node;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}

int main(){
//    test00_reverse();
//    return 0;

    string line;
    ListNode *preNode1 = new ListNode(0), *ptr1=preNode1;
    ListNode *preNode2 = new ListNode(0), *ptr2=preNode2;
    while(getline(cin, line)){
        if(preNode1->next == nullptr){
            istringstream args(line);
            int val;
            while(args>>val){
                ptr1->next = new ListNode(val);
                ptr1 = ptr1->next;
            }
        }else{
            istringstream args(line);
            int val;
            while(args>>val){
                ptr2->next = new ListNode(val);
                ptr2 = ptr2->next;
            }
        }
    }
    ListNode *ptr = Solution::addTwoNumbers(preNode1->next, preNode2->next);
    while(ptr){
        cout<< ptr->val<< " ";
        ptr = ptr->next;
    }
    cout<<endl;
    return 0;
}
