#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    int isPldrm(string& s, int i, int j, vector<vector<int>> &dp){
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            dp[i][j] = i+1>j-1?1:isPldrm(s, i+1, j-1, dp);
        }else{
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

   bool checkPartitioning(string s) {
       int n = s.length();
       vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -1));
       for(int i=0;i<n;i++){
           for(int j=i;j<n;j++){
               dp[i][j] = isPldrm(s, i, j, dp);
           }
       }
       for(int i=1;i<n-1;i++){
           for(int j=i;j<n-1;j++){
               if(dp[0][i-1] == 1 and dp[i][j] == 1
                       and dp[j+1][n-1] == 1){
                   return true;
               }
           }
       }
       return false;
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    string s = string(argv[1]);
    cout<<solution.checkPartitioning(s)<<endl;
    return 0;
}
