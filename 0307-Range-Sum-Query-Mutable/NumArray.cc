#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> arr;
    vector<int> tree;

    NumArray(vector<int>& nums) {
        arr = nums;
        int n = arr.size();
        tree = vector<int>(4*n, 0);
        build(0, n-1, 0);
    }
    
    void build(int l, int r, int p){
        if(l == r){
            tree[p] = arr[l];
            return ;
        }

        int mid = l + (r-l)/2;
        build(l, mid, 2*p+1);
        build(mid+1, r, 2*p+2);
        tree[p] = tree[2*p+1]+tree[2*p+2];
    }

    void update(int index, int val) {
        update(index, val, 0, arr.size()-1, 0);
    }
    
    void update(int index, int val, int l, int r, int p){
        if(index == l and index == r){
            tree[p] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index<=mid) update(index, val, l, mid, 2*p+1);
        else update(index, val, mid+1, r, 2*p+2);
        tree[p] = tree[p*2+1] + tree[p*2+2];
    }

    int sumRange(int left, int right) {
        return sumRange(left, right, 0, arr.size()-1, 0);
    }

    int sumRange(int nl, int nr, int l, int r, int p){
        if(nl<=l and nr>=r){
            return tree[p];
        }
        int mid = l + (r-l)/2;
        int sum = 0;
        if(nl<=mid) sum += sumRange(nl, nr, l, mid, 2*p+1);
        if(nr>mid)  sum += sumRange(nl, nr, mid+1, r, 2*p+2);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
int main(){
    return 0;
}
