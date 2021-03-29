struct Node{
    Node* pre;
    Node* next;
    int val;
    int key;
    Node(){}
    Node(int key_, int val_):val(val_), key(key_){}
};

class LRUCache {
public:
    map<int, Node*> tmap;
    int cnt = 0;
    int capacity_ = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        capacity_ = capacity;
    }
    
    void reorder(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }
    
    int get(int key) {
        if(tmap.find(key) != tmap.end()){
            reorder(tmap[key]);
            return tmap[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cnt == capacity_){
            if(tmap.find(key) == tmap.end()){
                auto node = new Node(key, value);
                node->next = head->next;
                head->next->pre = node;
                node->pre = head;
                head->next = node;
                tmap[key] = node;
                
                auto deletedNode = tail->pre;
                tail->pre = deletedNode->pre;
                deletedNode->pre->next = tail;
                tmap.erase(deletedNode->key);
            }else{
                auto node = tmap[key];
                node->val = value;
                reorder(node);
            }
        }else{
            if(tmap.find(key) == tmap.end()){
                auto node = new Node(key, value);
                node->next = head->next;
                head->next->pre = node;
                node->pre = head;
                head->next = node;
                tmap[key] = node;
                cnt += 1;
            }else{
                auto node = tmap[key];
                node->val = value;
                reorder(node);
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
