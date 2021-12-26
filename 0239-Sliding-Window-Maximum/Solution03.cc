#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

struct Node{
    int v;
    int i;
    Node(int v_, int i_){
        v = v_;
        i = i_;
    }
};

class Heap{
public:
    vector<Node*> arr;
    int k;
    int i=0;
    Heap(int k_){
        k = k_;
        arr = vector<Node*>(k, NULL);   
    }

    void build(Node* node){
        if(i==k) return;
        arr[i++] = node;
        up();
    }

    bool empty(){
        return i == 0;
    }

    int top(){
        return arr[0]->v;
    }

    void updateindex(vector<int>& l){
        for(int i=0;i<k;i++){
            l[arr[i]->i] = i;
        }
    }

    void update(int i, Node* node, vector<int>& l){
        arr[i] = node;
        int p = (i-1)/2;
        if(arr[p]->v < arr[i]->v){
            while(i>0 and arr[p]->v < arr[i]->v){
                l[arr[p]->i] = i;
                l[arr[i]->i] = p;
                swap(arr[p], arr[i]);
                i = p;
                p = (p-1)/2;
            }
        }else{
            int c = i;
            while(c<k){
                int c1 = c;
                if(c*2+1 < k and arr[c*2+1]->v > arr[c1]->v){
                    c1 = c*2+1;
                }
                if(c*2+2 < k and  arr[c*2+2]->v > arr[c1]->v){
                    c1 = c*2+2;
                }
                if(c1 != c){
                    l[arr[c]->i] = c1;
                    l[arr[c1]->i] = c;
                    swap(arr[c], arr[c1]);
                    c = c1;
                }else break;
            }
        }
    }

    void up(){
        int c=i-1;
        int p;
        while(c>0){
            p = c/2;
            if(arr[p]->v < arr[c]->v){
                swap(arr[p], arr[c]);
            }
            c = p;
        }
    }
            
};

class Solution{
    public:
        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            Heap h(k);
            vector<int> ret;
            int n = nums.size();
            vector<int> l(n, -1);
            for(int i=0;i<k;i++){
                h.build(new Node(nums[i], i));
            }
            h.updateindex(l);
            ret.push_back(h.top());
            for(int i=k;i<n;i++){
                l[i] = l[i-k];
                h.update(l[i], new Node(nums[i], i), l);
                ret.push_back(h.top());
            }
            return ret;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        int k;
        vector<int> nums;
        args>>k;
        int num;
        while(args>>num){
            nums.push_back(num);
        }
        auto result = Solution::maxSlidingWindow(nums, k);
        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
