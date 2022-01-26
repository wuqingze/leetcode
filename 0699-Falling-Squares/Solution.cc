#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
    int val;
    bool tag;
    Node(){
        val = 0;
        tag = false;
    }
};

class STree{
public:
    vector<int> arr;
    vector<Node> tree;

    STree(vector<int> &&arr_){
        arr = arr_;
        int n = arr.size();
        tree = vector<Node>(4*n, Node());
    }

    void pushtagdown(int p){
        if(tree[p].tag){
            int l = 2*p+1;
            int r = 2*p+2;
            tree[l].val = tree[p].val;
            tree[r].val = tree[p].val;
            tree[l].tag = true;
            tree[r].tag = true;
            tree[p].tag = false;
        }
    }

    int query(int l, int r){
        return query(l, r, 0, arr.size()-1, 0);
    }

    int query(int nl, int nr, int l, int r, int p){
        if(nl<=l and nr>=r){
            return tree[p].val;
        }
        pushtagdown(p);
        int mid = l + (r-l)/2;
        int mx = 0;
        if(nl<=mid) mx = max(mx, query(nl, nr, l, mid, 2*p+1));
        if(nr>mid)  mx = max(mx, query(nl, nr, mid+1, r, 2*p+2));
        return mx;
    }

    void update(int l, int r, int v){
        update(l, r, v, 0, arr.size()-1, 0);
    }

    void update(int nl, int nr, int v, int l, int r, int p){
        if(nl<=l and nr>=r){
            tree[p].val = v;;
            tree[p].tag = true;
            return;
        }
        pushtagdown(p);
        int mid = l+(r-l)/2;
        if(nl<=mid) update(nl, nr, v, l, mid, 2*p+1);
        if(nr>mid ) update(nl, nr, v, mid+1, r, 2*p+2);
        tree[p].val = max(tree[2*p+1].val, tree[2*p+2].val);
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> l1(2*n);
        for(int i=0;i<n;i++){
            l1[2*i] = positions[i][0];
            l1[2*i+1] = positions[i][0]+positions[i][1];
        }
        sort(l1.begin(), l1.end());
        vector<int> l2;
        int i=0;
        n = 2*n;
        while(i<n){
            int j = i;
            while(j<n and l1[i] == l1[j]) j+=1;
            l2.push_back(l1[i]);
            i = j;
        }
        n = l2.size();
        map<int, int> indexm;
        for(int i=0;i<n;i++){
            indexm[l2[i]] = i;
        }
        STree stree(vector<int>(n, 0));
        n = positions.size();
        vector<int> ret(n);
        for(int i=0;i<n;i++){
            auto pos = positions[i];
            int hight = stree.query(indexm[pos[0]], indexm[pos[0]+pos[1]]-1);
            stree.update(indexm[pos[0]], indexm[pos[0]+pos[1]]-1, hight+pos[1]);
            //ret[i] = stree.query(0, l2.size()-1);
            ret[i] = stree.tree[0].val;
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    int n = (argc-1)/2;
    vector<vector<int>> positions(n, vector<int>(2,0));
    for(int i=0;i<n;i++){
        positions[i][0] = atoi(argv[1+i*2]);
        positions[i][1] = atoi(argv[1+i*2+1]);
    }
    Solution solution;
    auto ret = solution.fallingSquares(positions);
    for(auto i:ret)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
