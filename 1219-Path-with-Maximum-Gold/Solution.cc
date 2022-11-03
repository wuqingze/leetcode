#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void f(vector<vector<int>>& grid, int m, int n, int i, int j, int presum, int& ret){
        if(i<0 or i>=m or j<0 or j>=n) return;
        if(grid[i][j] == -1) return;
        if(grid[i][j] == 0) return;

        presum += grid[i][j];
        ret = max(ret, presum);
        int t = grid[i][j];
        grid[i][j] = -1;
        f(grid, m, n, i+1, j, presum, ret);
        f(grid, m, n, i-1, j, presum, ret);
        f(grid, m, n, i, j+1, presum, ret);
        f(grid, m, n, i, j-1, presum, ret);
        grid[i][j] = t;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                f(grid, m, n, i, j, 0, ret);
            }
        }

        return ret;
    }
};

int main(){
    Solution solution;
    ///vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout<<solution.getMaximumGold(grid)<<endl;;
    return 0;
}
