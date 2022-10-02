#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    int f(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=i+1;k<j;k++){
            dp[i][j] = max(dp[i][j], nums[i]*nums[k]*nums[j]+
                          f(nums, i, k, dp)+f(nums, k, j, dp));
        }
        return dp[i][j];
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> bs;
        bs.push_back(1);
        for(int i=0;i<n;i++){
            bs.push_back(nums[i]);
        }
        bs.push_back(1);
        auto dp = vector<vector<int>>(n+2, vector<int>(n+2, -1));
        return f(bs, 0, n+1, dp);
    }
};
int main(int argc, char* argv[]){
    vector<int> nums(argc-1);
    for(int i=0;i<nums.size();i++){
        nums[i] = atoi(argv[i+1]);
    }
    Solution solution;
    auto ret = solution.maxCoins(nums);
    cout<<ret<<endl;
    return 0;
}
