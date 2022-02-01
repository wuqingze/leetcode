#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
struct Node{
    int len;
    int num;
    Node(){
        len = 0;
        num = 0;
    }
    
    Node(int len_, int num_){
        len = len_;
        num = num_;
    }
};

class STree{
public:
    vector<Node> tree;
    int LEN;
    STree(int n){
        tree = vector<Node>(4*n, Node());
        LEN = n;
    }
    
    Node query(int x){
        if(x<0) return Node(0, 0);
        return query(0, x, 0, LEN-1, 0);
    }
    
    Node query(int nl, int nr, int l, int r, int p){
        if(nl<=l and nr>=r){
            return tree[p];
        }
        Node mx(0,0);
        int mid = l + (r-l)/2;
        if(nl<=mid){
            auto node = query(nl, nr, l, mid, 2*p+1);
            if(node.len > mx.len) mx = node;
        }
        if(nr>mid){
            auto node =query(nl, nr, mid+1, r, 2*p+2);
            if(node.len > mx.len) mx = node;
            else if(node.len == mx.len) mx.num += node.num;
        }
        return mx;
    }
    
    Node q(int x){
        return q(x, 0, LEN-1, 0);
    }

    Node q(int x, int l, int r, int p){
        if(x == l and r==x){
            return tree[p];
        }
        int mid = l+(r-l)/2;
        if(x<=mid){
            return q(x, l, mid, 2*p+1);
        }else{
            return q(x, mid+1, r, 2*p+2);
        }
    }

    void insert(int x, Node &&v){
        insert(x, v, 0, LEN-1, 0);
    }
    
    void insert(int x, Node &v, int l, int r, int p){
        if(x == l and x==r){
            tree[p]=v;
            return;
        }
        
        int mid = l + (r-l)/2;
        if(x<=mid){
            insert(x, v, l, mid, 2*p+1);
        }else{
            insert(x, v, mid+1, r, 2*p+2);
        }
        Node lnode = tree[p*2+1];
        Node rnode = tree[p*2+2];
        if(lnode.len < rnode.len){
            tree[p].len = rnode.len;
            tree[p].num = rnode.num;
        }else if(lnode.len == rnode.len){
            tree[p].len = lnode.len;
            tree[p].num = lnode.num+rnode.num;
        }else{
            tree[p].len = lnode.len;
            tree[p].num = lnode.num;
        }
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> l1 = vector<int>(nums.begin(), nums.end());
        sort(l1.begin(), l1.end());
        vector<int> l2;
        int n = nums.size();
        int i=0;
        while(i<n){
            int j = i;
            while(j<n and l1[i]==l1[j]) j+=1;
            l2.push_back(l1[i]);
            i = j;
        }
        map<int, int> indexm;
        n = l2.size();
        for(int i=0;i<n;i++){
            indexm[l2[i]] = i;
        }
        
        STree tree(n);
        
        n = nums.size();
        map<int, int> maxm;
        for(int i=1;i<=n;i++) maxm[i] = 0;
        for(int i=0;i<n;i++){
            int index = indexm[nums[i]];
            Node v =tree.query(index-1);
            Node q = tree.q(index);
            if(v.len+1 == q.len){
                tree.insert(index, Node(v.len+1,q.num+v.num));
                maxm[v.len+1] += v.num;
            }else{
                tree.insert(index, Node(v.len+1, v.num==0?1:v.num));
                maxm[v.len+1] += v.num==0?1:v.num;
            }
        }
        int ret=0;;
        int mx=0;
        for(auto ptr=maxm.begin();ptr!=maxm.end();ptr++){
            if(ptr->second != 0 and ptr->first>mx){
                mx = ptr->first;
                ret = ptr->second;
            }
        }
        return ret;
    }
};
int main(int argc, char* argv[]){
    if(argc<2) return 0;
    vector<int> nums(argc-1);
    for(int i=0;i<nums.size();i++){
        nums[i] = atoi(argv[i+1]);
    }
    Solution solution;
    auto ret = solution.findNumberOfLIS(nums);
    cout<<ret<<endl;
    return 0;
}
