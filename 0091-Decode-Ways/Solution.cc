#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int f(const string &s, vector<int> &dp, int i, int n){
        if(i>=n) 
            return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0;

        if(i< n-1 and s.substr(i,2) <= "26"){
            dp[i] = f(s, dp, i+1, n) + f(s, dp, i+2, n);
        }else{
            dp[i] = f(s, dp, i+1, n);
        }
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(s, dp, 0, n);
    }
};
int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution s;
    cout<<s.numDecodings(string(argv[1]));
    return 0;
}
