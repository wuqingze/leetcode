#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void f(int i, int j, int m, int n, vector<vector<int>>& matrix, int& cnt){
        if(i<0 or j<0 or i>=m or j>=n) return;
        if(matrix[i][j] == -1) return;
        if(matrix[i][j] == 0) return ;
        matrix[i][j] = -1;
        cnt += 1;
        f(i+1, j, m, n, matrix, cnt);
        f(i-1, j, m, n, matrix, cnt);
        f(i, j+1, m, n, matrix, cnt);
        f(i, j-1, m, n, matrix, cnt);
    }

    int maximumArea(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        int ret = 0;
        int cnt;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt = 0;
                f(i, j, m, n, matrix, cnt);
                ret = max(cnt, ret);
            }
        }

        return ret;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},    
        {0,0,0,0,0,0,0,1,1,1,0,0,0},    
        {0,1,1,0,1,0,0,0,0,0,0,0,0},    
        {0,1,0,0,1,1,0,0,1,0,1,0,0},    
        {0,1,0,0,1,1,0,0,1,1,1,0,0},    
        {0,0,0,0,0,0,0,0,0,0,1,0,0},    
        {0,0,0,0,0,0,0,1,1,1,0,0,0},    
        {0,0,0,0,0,0,0,1,1,0,0,0,0},    
    };
    auto ret = solution.maximumArea(matrix);
    cout<<ret<<endl;
    return 0;
}
