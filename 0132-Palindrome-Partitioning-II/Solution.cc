#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void f(int pre, int i, int n, int count, int &ret, string& s, 
            vector<vector<int>> &dp){
        if(i==n){
            if(pre == n){
                ret = min(ret, count); 
            }
            return;
        }

        if(dp[pre][i] == -1)
            dp[pre][i] = isPalindrome(s, pre, i)?1:0;

        if(dp[pre][i] == 1){
            f(i+1, i+1, n, count+1, ret, s, dp);
            f(pre, i+1, n, count, ret, s, dp);
        }else{
            f(pre, i+1, n, count, ret, s, dp);
        }
    }
    int minCut(string s) {
        int ret = 0x7fffffff;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        f(0, 0, n, 0, ret, s, dp); 
        return ret-1;
    }
};
int main(int argc, char* argv[]){
    string s(argv[1]);
    cout<<Solution().minCut(s)<<endl;
    return 0;
}
