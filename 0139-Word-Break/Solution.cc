#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
    bool f(string &s, set<string> &dict, vector<int> &dp, int i, int n){
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
        for(int j=1;j<=20;j++){
            if(i+j<= n and dict.find(s.substr(i, j)) != dict.end()){
                bool ret = f(s, dict, dp, i+j, n);
                if(ret){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[i] == 1?true:false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(auto &word:wordDict) 
            dict.insert(word);
        int n = s.size(); 
        vector<int> dp(n, -1);
        return f(s, dict, dp, 0, n);
    }
};

int main(){
    string line;
    Solution solution;
    while(getline(cin, line)){
        istringstream is(line);
        string s;
        is>>s;
        string t;
        vector<string> wordDict;
        while(is>>t){
            wordDict.push_back(t);
        }
        auto ret = solution.wordBreak(s, wordDict);
        cout<<ret<<endl;
    }
    return 0;
}
