#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    bool isPldrm(string& s, int i, int j, map<pair<int, int>, int> &dp){
        if(i==j) return true;
        pair<int, int> key = {i, j};
        if(dp.count(key) != 0){
            return dp[key] == 0?false:true;
        }
        if(s[i] != s[j]){
            dp[key] = 0;
        }else{
            dp[key] = i+1>j-1?true:isPldrm(s, i+1, j-1, dp);
        }
        return dp[key]==0?false:true;
    }

    bool f(string &s, int i, int n, int k, map<pair<int, int>, int> &dp){
        if(k == 1){
            return isPldrm(s, i, n-1, dp);
        }

        for(int j=i;j<=n-k;j++){
            if(isPldrm(s, i, j, dp) and f(s, j+1, n, k-1, dp))
                return true;
        }
        return false;
    }

    bool checkPartitioning(string s) {
        int n = s.length();
        map<pair<int, int>, int> dp;
        return f(s, 0, n, 3, dp);
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    string s = string(argv[1]);
    cout<<solution.checkPartitioning(s)<<endl;
    return 0;
}
