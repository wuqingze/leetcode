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
                  int c = 0;
                  ListNode* tNode = cur;
                  while(c<k && tNode){ c+=1; tNode=tNode->next;}
                  if(c==k){
                      ListNode* headNode=nullptr;
                      ListNode* tailNode=cur;
                      ListNode* pNode = nullptr;
                      while(c>0){
                          if(c==1) headNode = cur;
                          ListNode* tNode = cur->next;
                          cur->next = pNode;
                          pNode = cur;
                          cur = tNode;
                          c-=1;
                      }
                      pre->next = headNode;
                      tailNode->next = cur;
                      pre = tailNode;
                  }else{
                      pre->next = cur;
                      cur = nullptr;
                  }
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
