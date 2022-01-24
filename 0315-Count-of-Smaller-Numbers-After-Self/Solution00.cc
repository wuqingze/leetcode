#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class STree{
public:
    vector<int> arr;
    vector<int> tree;

    STree(vector<int> &&arr_){
        arr = arr_;
        int n = arr.size();
        tree = vector<int>(4*n, 0);
        build(0, n-1);
    }

    void build(int l, int r, int p=0){
        if(l == r){
            tree[p] = arr[l];
            return;
        }

        int mid = l + (r-l)/2;
        build(l, mid, 2*p+1);
        build(mid+1, r, 2*p+2);

        tree[p] = tree[2*p+1] + tree[2*p+2];
    }

    int query(int l, int r){
        return query(l, r, 0, arr.size()-1, 0);
    }

    int query(int nl, int nr, int l, int r, int p=0){
        if(nl<=l and nr>=r){
            return tree[p];
        }

        int sum = 0;
        int mid  = l+(r-l)/2;
        if(nl<=mid){
            sum += query(nl, nr, l, mid, 2*p+1);
        }
        if(nr>mid){
            sum += query(nl, nr, mid+1, r, 2*p+2);
        }
        return sum;
    }

    void update(int i){
        update(i, 0, arr.size()-1, 0);
    }

    void update(int i, int l, int r, int p=0){
        if(i==l and i==r){
            tree[p] += 1;
            return;
        }
        int mid = l+(r-l)/2;
        if(i<=mid){
            update(i, l, mid, 2*p+1);
        }else{
            update(i, mid+1, r, 2*p+2);
        }
        tree[p] = tree[p*2+1]+tree[2*p+2];
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        auto l1 = vector<int>(nums.begin(), nums.end());
        sort(l1.begin(), l1.end());
        int i=0;
        int n = nums.size();
        vector<int> l2;
        while(i<n){
            int j=i;
            while(j<n and l1[i] == l1[j]) j+=1;
            l2.push_back(l1[i]);
            i = j;
        }
        map<int, int> indexm;
        n = l2.size();
        for(int i=0;i<n;i++){
            indexm[l2[i]] = i;
        }
        STree tree(vector<int>(n, 0));
        int m = nums.size();
        vector<int> ret;
        for(int i=m-1;i>=0;i--){
            int index = indexm[nums[i]];
            int v = index==0?0:tree.query(0, index-1);
            ret.push_back(v);
            tree.update(index);
        }
        reverse(ret.begin(), ret.end());
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
    auto ret = solution.countSmaller(nums);
    for(auto i: ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
