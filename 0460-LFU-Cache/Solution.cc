#include <iostream>
#include <map>
#include <vector>

using namespace std;


struct Node{
    int v;
    int c;
    int k;
    Node(int v_, int c_, int k_){
        v = v_;
        c = c_;
        k = k_;
    }
};

class Heap{
public:
    int capacity;
    int len;
    vector<Node*> arr;
    
    Heap(){}
    Heap(int cap_){
        capacity = cap_;
        len = 0;
        arr = vector<Node*>(capacity, NULL);
    }
    
    int find(int index, map<int, int> &hmap){
        int ret = arr[index]->v;
        arr[index]->c += 1;
        update(index, hmap);
        return ret;
    }
    
    void update(int index, int value, map<int,int> &hmap){
        arr[index]->v = value;
        arr[index]->c += 1;
        update(index, hmap);
    }
    
    void update(int i, map<int,int> &hmap){
        if(i>=len) return;
        int mn = i;
        int child = 2*i+1;
        if(child < len and arr[child]->c <= arr[mn]->c){
            hmap[arr[child]->k] = mn;
            hmap[arr[mn]->k] = child;
            swap(arr[child], arr[mn]);
            mn = child;
        }
        child = 2*i+2;
        if(child<len and arr[child]->c <= arr[mn]->c){
            hmap[arr[child]->k] = mn;
            hmap[arr[mn]->k] = child;
            swap(arr[child], arr[mn]);
            mn = child;
        }
        if(mn != i){
            update(mn, hmap);
        }
    }
    
    void removeHead(map<int, int> &hmap){
        if(len > 0){
            auto head = arr[0];
            hmap.erase(hmap.find(head->k));
            arr[0] = arr[len-1];
            len -= 1;
            update(0, hmap);
        }
    }
    
    Node* head(){
        if(len == 0) return NULL;
        else return arr[0];
    }
    
    void insert(Node* node, map<int, int> &hmap){
        arr[len++] = node;
        hmap[node->k] = len-1;
        update1(len-1, hmap);
    }
    
    void update1(int i, map<int, int> &hmap){
        if(i==0){
            hmap[arr[i]->k] = 0;
            return;
        }
        
        int p = (i-1)/2;
        if(arr[p]->c > arr[i]->c){
            hmap[arr[p]->k] = i;
            hmap[arr[i]->k] = p;
            swap(arr[p], arr[i]);
            update1(p, hmap);
        }
    }
};

class LFUCache {
public:
    Heap heap;
    map<int, int> hmap;
    int capacity;
    
    LFUCache(int capacity_) {
        capacity = capacity_;
        heap = Heap(capacity);
    }
    
    int get(int key) {
        if(capacity == 0 or hmap.count(key) == 0){
            return -1;
        }
        return heap.find(hmap[key], hmap);
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(hmap.count(key) != 0){
            heap.update(hmap[key], value, hmap);
            return;
        }

        if(heap.len == capacity){
            heap.removeHead(hmap);
        }
        heap.insert(new Node(value, 1, key), hmap);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LFUCache obj = LFUCache(3);
    obj.put(1,1);
    obj.put(2,2);
    obj.put(3,3);
    obj.put(4,4);
    obj.get(4);
    obj.get(3);
    obj.get(2);
    obj.get(1);
    obj.put(5,5);
    obj.get(1);
    obj.get(2);
    obj.get(3);
    obj.get(4);
    obj.get(5);
    return 0;
}
