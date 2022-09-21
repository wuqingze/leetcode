class Solution {
public:
    int f(int i, int j, int n, vector<int> &nums){
        auto dp = vector<pair<int, bool>>(n);
        dp[j]={nums[j],true};
        if(nums[j-1]>nums[j]){
            dp[j-1] = {nums[j-1], true};
        }else{
            dp[j-1] = {nums[j], false};
        }
        for(int k=j-2;k>=i;k--){
            if(dp[k+1].second){
                if(nums[k]+dp[k+2].first>dp[k+1].first){
                    dp[k] = {nums[k]+dp[k+2].first, true};
                }else{
                    dp[k] = {dp[k+1].first, false};
                }
            }else{
                dp[k] = {nums[k]+dp[k+1].first, true};
            }
        }
        return dp[i].first;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));
        
        return max(f(0, n-2, n, nums), f(1, n-1, n, nums));
    }
};
