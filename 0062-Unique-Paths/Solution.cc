#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int f(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i<0 or i>=m or j<0 or j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==m-1 and j==n-1){
            dp[i][j] = 1;
        }else{
            dp[i][j] = f(m, n, i+1, j, dp)+f(m, n, i, j+1, dp);
        }
//        cout<<i<<","<<j<<"--"<<dp[i][j]<<endl;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m, n, 0, 0, dp);
    }
};

int main(){
    Solution solution;
    cout<<solution.uniquePaths(3,7)<<endl;
    return 0;
}
