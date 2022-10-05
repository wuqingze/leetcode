class Solution {
public:
    vector<long long> dp;
    Solution(){
        dp = vector<long long>(50);
        int n = dp.size();
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
    }
    
    int fib(int n) {
        return dp[n];
    }
};
