#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>> &dungeon,
            vector<vector<int>> &dp){
        if(i>=m or j>=n) return 0x80000000;
        if(i==m-1 and j==n-1) return dungeon[i][j]>0?0:dungeon[i][j];
        if(dp[i][j] != 1) return dp[i][j];
        int r = f(i,j+1,m,n, dungeon, dp);
        int d = f(i+1, j, m, n, dungeon, dp);
        if(r==0 or d==0){
            dp[i][j] = dungeon[i][j]>0?0:dungeon[i][j];
        }else{
            dp[i][j] = dungeon[i][j]+std::max(r,d)>0?0:dungeon[i][j]+std::max(r,d);
        }
        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 1));
        return 1-f(0,0,m,n, dungeon, dp);
    }
};

int main(){
    vector<vector<int>> dungeon = {
        {-2, -3,  3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    Solution s;
    cout<<s.calculateMinimumHP(dungeon)<<endl;
    return 0;
}
