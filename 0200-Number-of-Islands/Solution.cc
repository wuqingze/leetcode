class Solution {
public:
    void f(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(not(i<m and i>=0 and j<n and j>= 0)){
            return;
        }
        if(grid[i][j] != '1') return;
        grid[i][j] = -1;
        f(grid,i+1,j,m,n);
        f(grid,i-1,j,m,n);
        f(grid,i,j-1,m,n);
        f(grid,i,j+1,m,n);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    ret += 1;
                    f(grid, i, j, m, n);
                }
            }
        }
        return ret;
    }
};
