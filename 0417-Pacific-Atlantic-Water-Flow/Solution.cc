#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int INT_MAX = 0x7fffffff;
    bool f1(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<int>>& dp, int pre){
        if(i==m or j==n) return true;
        if(i<0 or j<0) return false;
        if(heights[i][j] == -1) return false;
        if(heights[i][j] > pre) return false;
        if(dp[i][j] != 0) return dp[i][j]>0?true:false;

        int t = heights[i][j];
        heights[i][j] = -1;
        bool ret = f1(heights, i-1, j, m, n, dp, t) or
                   f1(heights, i+1, j, m, n, dp, t) or
                   f1(heights, i, j-1, m, n, dp, t) or
                   f1(heights, i, j+1, m, n, dp, t);
        dp[i][j] = ret?1:-1;
        heights[i][j] = t;
        return ret;
    }

    bool f2(vector<vector<int>>& heights, int i, int j, int m, int n, vector<vector<int>>& dp, int pre){
        if(i<0 or j<0) return true;
        if(i>=m or j>=n) return false;
        if(heights[i][j] == -1) return false;
        if(heights[i][j] > pre) return false;
        if(dp[i][j] != 0) return dp[i][j]>0?true:false;

        int t = heights[i][j];
        heights[i][j] = -1;
        bool ret = f2(heights, i-1, j, m, n, dp, t) or
                   f2(heights, i+1, j, m, n, dp, t) or
                   f2(heights, i, j-1, m, n, dp, t) or
                   f2(heights, i, j+1, m, n, dp, t);
        dp[i][j] = ret?1:-1;
        heights[i][j] = t;
        return ret;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dp1(m, vector<int>(n, 0));
        vector<vector<int>> dp2(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                f1(heights, i, j, m, n, dp1, INT_MAX);
                f2(heights, i, j, m, n, dp2, INT_MAX);
            }
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp1[i][j]==1 and dp2[i][j]==1)
                    res.push_back({i, j});
             }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto ret = solution.pacificAtlantic(heights);
    for(auto pos:ret)
        cout<<pos[0]<<","<<pos[1]<<endl;
    return 0;
}

