#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int v;
    int w;
    int p;
    Node(){}
    Node(int v_, int w_, int p_):v(v_),w(w_),p(p_){}
};

class Heap{
public:
    vector<Node> arr;
    vector<int> indexs;
    int len;
    int size;

    Heap(int n){
        arr = vector<Node>(n);
        indexs = vector<int>(n+1, -1);
        len = n;
        size = 0;
    };

    int push(Node node){
        arr[size++] = node;
        indexs[node.v] = size-1;
        int i = size-1;
        int p = (i-1)/2;
        while(i>0){
            if(arr[i].w<arr[p].w){
                std::swap(arr[i], arr[p]);
                std::swap(indexs[arr[i].v], indexs[arr[p].v]);
                i = p;
                p = (i-1)/2;
            }else break;
        }
        return i;
    }

    Node top(){
        if(size == 1){
            indexs[arr[0].v] = -2;
            size -= 1;
            return arr[0];
        }

        auto res = arr[0];
        indexs[arr[0].v] = -2;
        arr[0] = arr[--size];
        indexs[arr[0].v] = 0;

        int i=0;
        int l,r,t;
        while(i<size){
            t = i;
            l = 2*i+1;
            r = 2*i+2;
            if(l<size and arr[t].w>arr[l].w){
                t = l;
            }
            if(r<size and arr[t].w>arr[r].w){
                t = r;
            }
            if(t == i){
                break;
            }else{
                std::swap(indexs[arr[i].v], indexs[arr[t].v]);
                std::swap(arr[i], arr[t]);
            }
            i = t;
        }
        return res;
    }

    bool empty(){
        return size==0;
    }

    void update(int v, int w, int pre){
        arr[indexs[v]].w = w;
        arr[indexs[v]].p = pre;
        int i = indexs[v];
        int p;
        while(i>0){
            p = (i-1)/2;
            if(arr[p].w > arr[i].w){
                std::swap(indexs[arr[p].v], indexs[arr[i].v]);
                std::swap(arr[p], arr[i]);
                i = p;
            }else{
                break;
            }
        }
    }

};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> matrix(n+1, vector<int>(n+1, -1));
        for(auto &entry:times){
            matrix[entry[0]][entry[1]] = entry[2];
        }
        Heap heap(n);
        heap.push(Node(k, 0, k));
        int cnt = 0;
        Node node;
        while(not heap.empty()){
            node = heap.top();
            cnt += 1;
            int i = node.v;
            for(int j=1;j<=n;j++){
                if(matrix[i][j] != -1){
                    if(heap.indexs[j] == -1){
                        heap.push(Node(j, matrix[i][j]+node.w, node.v));
                    }else if(heap.indexs[j] == -2){
                    }else{
                        if(node.w+matrix[i][j] < heap.arr[heap.indexs[j]].w){
                            heap.update(j, node.w+matrix[i][j], node.v);
                        }
                    }
                }
            }
        }
        return cnt == n?node.w:-1;
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    int t;
    vector<vector<int>> times;
    while(cin>>t){
        vector<int> time(3);
        time[0] = t;
        cin>>t;
        time[1] = t;
        cin>>t;
        time[2] = t;
        times.push_back(time);
    }
    Solution solution;
    auto res = solution.networkDelayTime(times, n, k);
    cout<<res;
    return 0;
}
