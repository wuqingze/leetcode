#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node{
    int k;
    int v;
    int c;
    Node* pre;
    Node* next;
    Node(){
        pre = NULL;
        next = NULL;
    }
    
    Node(int k_, int v_, int c_){
        k = k_;
        v = v_;
        c = c_;
        Node();
    }
};

class LFUCache {
public:
    Node* head;
    Node* tail;
    int capacity;
    map<int, Node*> hmap;
    int len;
    
    LFUCache(int capacity_) {
        capacity = capacity_;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        len =0;
    }
    
    void update(Node* node){
        auto ptr = node;
        while(ptr!=tail and ptr->c>=node->c) ptr=ptr->next;
        node->next->pre = node->pre;
        node->pre->next = node->next;
        ptr->pre->next = node;
        node->pre = ptr->pre;
        ptr->pre = node;
        node->next = ptr;
    }
    
    int get(int key) {
        if(capacity==0 or hmap.count(key)==0){
            return -1;
        }
        auto node = hmap[key];
        node->c += 1;
        update(node);
        return node->v;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(hmap.count(key)==0){
            if(len == capacity){
                auto node = head->next;
                hmap.erase(hmap.find(node->k));
                node->k = key;
                node->v = value;
                node->c = 1;
                hmap[key] = node;
                update(node);
            }else{
                auto node = new Node(key, value, 1);
                hmap[key] = node;
                len += 1;
                if(len == 1){
                    head->next = node;
                    node->pre = head;
                    tail->pre = node;
                    node->next = tail;
                }else{
                    head->next->pre = node;
                    node->next = head->next;
                    head->next = node;
                    node->pre = head;
                    update(node);
                }
            }
        }else{
            auto node = hmap[key];
            node->v = value;
            node->c += 1;
            update(node);
        }
    }
};

int main(){
    LFUCache obj = LFUCache(2);
    obj.put(1,1);
    obj.put(2,2);
    obj.get(1);
    obj.put(3,3);
    obj.get(2);
	return 0;
}
