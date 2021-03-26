#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
    bool f(string &s, int i, int n, vector<string> &ret,
            set<string> &dict, vector<int> &dp, vector<string> &pre){
        if(i==n){
            if(pre.size() !=0){
                string t = "";
                for(int j=0;j<pre.size()-1;j++){
                    t += pre[j]+" ";
                }
                t += pre[pre.size()-1];
                ret.push_back(t);
            }
            return true;
        }
        if(dp[i] == 0) return false;
        dp[i] = 0;
        for(int j=1;j<=10;j++){
            if(i+j<=n and dict.find(s.substr(i, j)) != dict.end()){
                pre.push_back(s.substr(i, j));
                auto t = f(s, i+j, n, ret, dict, dp, pre);
                if(t){
                    dp[i] = true;
                }
                pre.pop_back();
            }
        }
        return dp[i] == 1?true:false;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> ret;
        set<string> dict;
        for(auto &word:wordDict)
            dict.insert(word);
        vector<int> dp(n, -1);
        vector<string> pre;
        f(s,0, n, ret, dict, dp, pre); 
        return ret;
    }
};

int main(){
    string line;
    Solution solution;
    while(getline(cin, line)){
        istringstream is(line);
        string s;
        is>>s;
        vector<string>  wordDict;
        string t;
        while(is>>t)
            wordDict.push_back(t);
        auto ret = solution.wordBreak(s, wordDict);
        if(ret.size() == 0) continue;
        for(auto &word: ret){
            cout<<word<<endl;
        }
        cout<<"--------------------\n";
    }
    return 0;
}
