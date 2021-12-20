#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int f(vector<int> &prices, int i, int k,int n, vector<vector<int>> &dp){
        if(k == 0) return 0;
        if(i>=n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int mx = 0;
        for(int j=i;j<n;j++){
            if(j==i){
                mx = max(mx, f(prices, i+1, k, n, dp));
            }else{
                mx = max(mx, prices[j]-prices[i]+f(prices, j+1, k-1, n, dp));
            }
        }
        dp[i][k] = mx;
        return dp[i][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        return f(prices, 0, k, n, dp);
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    int k = atoi(argv[1]);
    int n = argc-2;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        prices[i] = atoi(argv[2+i]);
    }
    cout<<solution.maxProfit(k, prices);
    return 0;
}
