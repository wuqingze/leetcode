#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:    
    int f(int i, int j, int m, int n, string& s, string& t,
            vector<vector<int>>& dp){
        if(j>=n) return 1;
        if(i>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            dp[i][j] = f(i+1, j+1, m, n, s, t, dp) + f(i+1, j, m, n, s, t, dp);
        }else{
            dp[i][j] = f(i+1, j, m, n, s, t, dp);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t){
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, s, t, dp);
    }

};

int main(int argc, char* argv[]){
    string s(argv[1]);
    string t(argv[2]);
    Solution solution;
    auto ret = solution.numDistinct(s, t);
    cout<<ret<<endl;
    return 0;
}
