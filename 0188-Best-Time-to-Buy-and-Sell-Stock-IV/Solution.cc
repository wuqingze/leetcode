#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int f(int i, int j, int k, int n, vector<int> &prices, vector<vector<int>> &dp){
        if(k<=0){
            return 0;
        }
        if(j>=n) return i==-1?0:-prices[i];
        if(i==-1){
            if(dp[j][k] == -1){
                dp[j][k] = max(
                    f(-1, j+1, k, n, prices, dp),
                    f(j, j+1, k, n, prices, dp)
                );    
            }
            return dp[j][k];
        }else{
            return max(
                    prices[j] - prices[i],
                    f(i, j+1, k, n, prices, dp)
                    );
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) return 0;
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(-1, 0, k, n, prices, dp);
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
