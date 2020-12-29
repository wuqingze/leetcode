#include <iostream>
#include <sstream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* node):val(x), next(node){}
};

class Solution{

    public:
          static ListNode* reverseKGroup(ListNode* head, int k) {
              if(!head || !head->next) return head;
              ListNode* preHead = new ListNode();
              ListNode* pre = preHead;

              ListNode* cur = head;
              while(cur){
                  ListNode* pNode = nullptr;
                  ListNode* tailNode = cur;
                  ListNode* headNode = nullptr;
                  int c = 0;
                  while(c<k && cur){
                      c += 1;
                      if(c==k || !cur->next){ headNode = cur;}
                      ListNode* t = cur->next;
                      cur->next = pNode;
                      pNode = cur;
                      cur = t;
                  }
                  pre->next = headNode;
                  tailNode->next = cur;
                  pre = tailNode;
              }
              return preHead->next;
          }
};

int main(){
    string line;
    while(getline(cin, line)){
        int k;
        istringstream is(line);
        is>>k;
        ListNode* preHead = new ListNode();
        ListNode* pre = preHead;
        int n;
        while(is>>n){
            pre->next = new ListNode(n);
            pre = pre->next;
        }
        auto node = Solution::reverseKGroup(preHead->next, k);
        cout<<line<<endl;
        while(node){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl<<endl;;
    }
    return 0;
}
