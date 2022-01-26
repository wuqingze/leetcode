#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct Node{
    int mx, mn;
    bool tag;
    Node(){
        mx = 0;
        mn = 0;
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
        tree = vector<Node>(4*n);
    }

    void update(int l, int r, int v){
        update(l, r, v, 0, arr.size()-1, 0);
    }

    void pushtagdown(int p){
        if(tree[p].tag){
            int l = 2*p+1;
            int r = 2*p+2;
            tree[l].mx = tree[p].mx;
            tree[l].mn = tree[p].mn;
            tree[r].mx = tree[p].mx;
            tree[r].mn = tree[p].mn;
            tree[p].tag = false;
            tree[l].tag = true;
            tree[r].tag = true;
        }
    }

    void update(int nl, int nr, int v, int l, int r, int p=0){
        if(nl<=l and nr>=r){
            if(v>tree[p].mx){
                tree[p].mx = v;
                tree[p].mn = v;
                tree[p].tag = true;
            }else if(v<= tree[p].mn){
            }else{
                if(l == r) return;
                int mid = l+(r-l)/2;
                update(nl, nr, v, l, mid, 2*p+1);
                update(nl, nr, v, mid+1, r, 2*p+2);
            }
            return;
        }
        pushtagdown(p);
        int mid = l + (r-l)/2;
        if(nl<= mid) update(nl, nr, v, l, mid, 2*p+1);
        if(nr> mid) update(nl, nr, v, mid+1, r, 2*p+2);
        tree[p].mx = max(tree[2*p+1].mx, tree[2*p+2].mx);
        tree[p].mn = min(tree[2*p+1].mn, tree[2*p+2].mn);
    }

    void traverse(vector<vector<int>> &ret, vector<int> &f){
        traverse(0, arr.size()-1, 0, ret, f);
    }

    void traverse(int l, int r, int p, vector<vector<int>> &ret, vector<int> &f){
        if(l==r){
            ret.push_back({f[l], tree[p].mx});
            return;
        }
        pushtagdown(p);
        int mid = l + (r-l)/2;
        traverse(l, mid, 2*p+1, ret, f);
        traverse(mid+1, r, 2*p+2, ret, f);
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> l1;
        for(auto bd:buildings){
            l1.push_back(bd[0]);
            l1.push_back(bd[1]);
        }

        sort(l1.begin(), l1.end());
        vector<int> l2;
        int n = l1.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n and l1[i] == l1[j]) j+=1;
            l2.push_back(l1[i]);
            i = j;
        }
        n = l2.size();
        map<int, int> indexm;
        for(int i=0;i<n;i++){
            indexm[l2[i]] = i;
        }
        STree tree(vector<int>(n, 0));
        for(auto &bd:buildings){
            int l = indexm[bd[0]];
            int r = indexm[bd[1]];
            int v = bd[2];
            tree.update(l, r-1, v);
        }
        vector<vector<int>> ret;
        tree.traverse(ret, l2);
        vector<vector<int>> ret1;
        i=0;
        n = ret.size();
        while(i<n){
            int j = i;
            while(j<n and ret[i][1] == ret[j][1]) j+=1;
            ret1.push_back(ret[i]);
            i=j;
        }
        return ret1;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    int n = (argc-1)/3;
    vector<vector<int>> buildings(n);
    for(int i=0;i<n;i++){
        buildings[i] = {atoi(argv[i*3+1]),atoi(argv[i*3+2]),atoi(argv[i*3+3])};
    }
    Solution solution;
    auto ret = solution.getSkyline(buildings);
    for(auto &item:ret){
        cout<<"["<<item[0]<<","<<item[1]<<"],";
    }
    cout<<endl;
    return 0;
}
