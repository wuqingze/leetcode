// struct Node{
//     int val;
//     int mn;
//     Node* next;
    
//     Node(int val_, int mn_, Node* next_){
//         val = val_;
//         mn = mn_;
//         next = next_;
//     }
// };

// class MinStack {
// public:
//     Node* head = nullptr;
//     /** initialize your data structure here. */
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(head){
//             head = new Node(val, min(val, head->mn), head);
//         }else{
//             head = new Node(val, val, head);
//         }
//     }
    
//     void pop() {
//         auto t = head;
//         head = head->next;
//         delete t;
//     }
    
//     int top() {
//         return head->val;
//     }
    
//     int getMin() {
//         return head->mn;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
public:
    stack<pair<int, int>> stck;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if(stck.empty()){
            stck.push({val, val});
        }else{
            stck.push({val, min(val, stck.top().second)});
        }
    }
    
    void pop() {
        stck.pop();
    }
    
    int top() {
        return stck.top().first;
    }
    
    int getMin() {
        return stck.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
