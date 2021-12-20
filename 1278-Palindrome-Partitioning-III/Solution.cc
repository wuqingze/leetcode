#include <string> 
#include <map> 
#include <iostream> 

using namespace std;
class Solution {
public:
    int countPldrmChanged(string &s, int i, int j){
        int ret = 0;
        while(i<j){
            if(s[i] != s[j])
                ret += 1;
            i += 1;
            j -= 1;
        }
        return ret;
    }

    int f(string &s, int i, int n, int k, map<pair<int,int>, int> &dp){
        pair<int, int> key = {i,k}; 
        if(dp.count({i, k})) return dp[key];
        if(n-i == k) {
            dp[key] = 0;
            return 0;
        }
        if(k == 1){
            dp[key] = countPldrmChanged(s, i, n-1);
            return dp[key];
        }

        int mn = 0x7fffffff;
        for(int j=i;j<=n-k;j++){
            mn = min(mn, f(s,j+1, n, k-1, dp)+countPldrmChanged(s, i, j)); 
        }
        dp[key] = mn;
        return dp[key];
    }

    int palindromePartition(string s, int k) {
        int n = s.length();
        map<pair<int, int>,int> dp;
        return f(s, 0, n, k, dp);
    }
};

int main(int argc, char* argv[]){
    string s = string(argv[1]);
    int k = atoi(argv[2]);
    Solution solution;
    cout<<solution.palindromePartition(s, k)<<endl;
    return 0;
}
