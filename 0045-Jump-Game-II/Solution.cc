#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int INT_MAX = 0X7FFFFFFF;

    void update(int i, int v, int n,vector<int>& sgmtree){
        update(i, i, 0, n-1, v, 0, sgmtree);
    }

    void update(int i, int j, int l, int r, int v, int p, vector<int>& sgmtree){
        if(j<l or i>r) return;
        if(l==r){
            sgmtree[p] = v;
            return;
        }
        sgmtree[p] = min(sgmtree[p], v);
        int mid = l+(r-l)/2;
        update(i, j, l, mid, v, 2*p+1, sgmtree);
        update(i, j, mid+1, r, v, 2*p+2, sgmtree);
    }

    int getmin(int i, int j, int n,vector<int>& sgmtree){
        return getmin(i, j, 0, n-1, 0, sgmtree);
    }

    int getmin(int i, int j, int l, int r, int p, vector<int>& sgmtree){
        if(i>j) return INT_MAX;
        if(j<l or i>r) return INT_MAX;
        if(i<=l and j>=r) return sgmtree[p];

        int mid = l+(r-l)/2;
        return min(
                getmin(i, j, l, mid, 2*p+1, sgmtree),
                getmin(i, j, mid+1, r, 2*p+2, sgmtree)
                )
            ;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        int m = 2*n-1;
        vector<int> sgmtree(m, INT_MAX);
        vector<int> dp(n);
        dp[n-1] = 0;
        update(n-1, 0, n,sgmtree);
        for(int i=n-2;i>=0;i--){
            int t = getmin(i+1,i+nums[i], n, sgmtree);
            if(t == INT_MAX) dp[i] = INT_MAX;
            else dp[i] = t+1;
            update(i, dp[i], n, sgmtree);
        }
        return dp[0];
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,0,1,4};
    //vector<int> nums = {2,3,1,1,4};
    int ret = solution.jump(nums);
    cout<<ret<<endl;
//    cout<<solution.jump(nums)<<endl;
    return 0;
}
