#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class STree{
public:
    vector<int> tree;
    int LEN;
    STree(int n){
        LEN = n;
        tree = vector<int>(4*n, 0);
    }
    
    int query(int x){
        return query(x, LEN-1, 0, LEN-1, 0);
    }
    
    int query(int nl, int nr, int l, int r, int p){
        if(nl<=l and nr>=r){
            return tree[p];
        }
        
        int mid = l + (r-l)/2;
        int sum = 0;
        if(nl<=mid){
            sum += query(nl, nr, l, mid, 2*p+1);
        }
        if(nr > mid){
            sum += query(nl, nr, mid+1, r, 2*p+2);
        }
        return sum;
    }
    
    void insert(int x){
        insert(x, 0, LEN-1, 0);
    }
    
    void insert(int x, int l, int r, int p){
        if(x == l and x == r){
            tree[p] += 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(x<=mid){
            insert(x, l, mid, 2*p+1);
        }else{
            insert(x, mid+1, r, 2*p+2);
        }
        tree[p] = tree[2*p+1] + tree[2*p+2];
    }
};

class Solution {
public:
    int find(vector<int> &nums, long target){
        int n = nums.size();
        int l=0;
        int r=n-1;
        int mid;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                l = mid + 1;
            }else{
                if(mid>0 and nums[mid-1]< target) return mid;
                r = mid -1;
            }
        }
        return l;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> l1 = vector<int>(nums.begin(), nums.end());
        sort(l1.begin(), l1.end());
        int n = nums.size();
        vector<int> l2;
        int i=0;
        while(i<n){
            int j= i;
            while(j<n and l1[i] == l1[j]) j+= 1;
            l2.push_back(l1[i]);
            i = j;
        }
        n = l2.size();
        map<int, int> indexm;
        for(int i=0;i<n;i++){
            indexm[l2[i]] = i;
        }
        STree tree(n);
        n = nums.size();
        int ret = 0;
        for(int i=0;i<n;i++){
            long target = 2*(long)nums[i]+1;
            if(target<=l2.back()){
                int index = find(l2, target);
                ret +=  tree.query(index);
            }
            tree.insert(indexm[nums[i]]);
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    int a = -2147483647;
    long b = 2*((long)a)+1;
    int c = 0x602000000a10;
    cout<<c<<endl;
    return 0;
    if(argc<2) return 0;
    vector<int> nums(argc-1);
    for(int i=0;i<nums.size();i++){
        nums[i] = atoi(argv[i+1]);
    }
    Solution solution;
    auto ret = solution.reversePairs(nums);
    cout<<ret<<endl;
    return 0;
}
