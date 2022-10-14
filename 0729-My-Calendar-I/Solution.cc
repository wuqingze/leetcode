#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node{
    int start;
    int end;
    Node* l;
    Node* r;
    Node(int s, int e){
        start = s;
        end = e;
    }
};
/**
class MyCalendar {
private:
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        for (const auto [s, e] : calendar) {
            if (start < e && s < end) return false;
        }
        calendar.emplace_back(start, end);
        return true;
    }
};
**/

class MyCalendar {
public:
    Node* root = nullptr;
    MyCalendar() {
    }
    
    void free(Node* node){
        if(node == nullptr) return;
        free(node->l);
        free(node->r);
        node->l = nullptr;
        node->r = nullptr;
        delete(node);
    }

    bool f(Node* node,Node* p, int start, int end){
        if(node == nullptr){
            fix(node, p, start, end);
            return true;
        }

        if(start>node->end or end < node->start){
            fix(node, p, start, end);
            return true;
        }

        if(start <= node->start or end >= node->end){
    //        fix(node, p, start, end);
            return false;
        }else{
            return f(node->l, node, start, end) and
                f(node->r, node, start, end);
        }
    }

    void fix(Node* node, Node* p, int start, int end){
        if(root == nullptr){
            root = new Node(start, end);
            return;
        }

        if(start <= node->start and end >= node->end){
            node->start = start;
            node->end = end;
            free(node->l);
            free(node->r);
            node->l = nullptr;
            node->r = nullptr;
            return;
        }

        if(start > node->end or end < node->start){
            auto node1 = new Node(start, end);
            auto node2 = new Node(node->start, node->end);
            node2->start = min(node1->start, node->start);
            node2->end = max(node1->end, node->end);
            if(start > node->end){
                node2->l = node;
                node2->r = node1;
            }else{
                node2->l = node1;
                node2->r = node;
            }

            if(node == root){
                root = node2;
            }else{
                if(p->l == node){
                    p->l = node2;
                }else{
                    p->r = node2;
                }
            }
        }else{
            node->start = min(node->start, start);
            node->end = max(node->end, end);
            if(node->l != nullptr){
                fix(node->l, node, start, end);
                fix(node->r, node, start, end);
            }
        }
    }

    bool book(int start, int end) {
        return f(root, nullptr, start, end-1);
    }
};

int main(){
    MyCalendar c;
    cout<<c.book(10, 20)<<endl;;
    cout<<c.book(15, 25)<<endl;;
    cout<<c.book(20, 30)<<endl;;
    cout<<"-----"<<endl;
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(8);
    s.insert(10);
    auto itr = s.lower_bound(4);
    cout<<*itr<<endl;
    itr ++;
//    itr += 1;
    cout<<*itr<<endl;
    set<pair<int,int>> ss;
    ss.insert({1,9});
    ss.insert({3,6});
    ss.insert({9,1});
    auto ii = ss.lower_bound({2,100});
    cout<<ii->second<<endl;
    return 0;
}
