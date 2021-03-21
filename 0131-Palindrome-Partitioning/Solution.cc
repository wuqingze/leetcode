#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }

    void f(string& s, int pre, int i, int n, vector<pair<int, int>> &l,
            vector<vector<int>> &dp, vector<vector<string>> &ret){
        if(i==n){
            if(pre ==n and l.size()>0){
                vector<string> t;
                for(auto &index:l){
                    t.push_back(s.substr(index.first, index.second-index.first+1));
                }
                ret.push_back(t);
            }
            return;
        }

        if(dp[pre][i] == -1)
            dp[pre][i] = isPalindrome(s, pre, i)?1:0;

        if(dp[pre][i] == 1){
            l.push_back({pre, i});
            f(s, i+1, i+1, n, l, dp, ret);
            l.pop_back();
            f(s, pre, i+1, n, l, dp, ret);
        }else{
            f(s, pre, i+1, n, l, dp, ret);
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<pair<int, int>> l;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<string>> ret;
        f(s, 0, 0, n, l, dp, ret); 
        return ret;
    }
};

int main(int argc, char* argv[]){
    string s(argv[1]);
    Solution solution;
    auto ret = solution.partition(s);
    for(auto &l:ret){
        for(auto &str:l){
            cout<<str<<" ";
        }
        cout<<endl;
    }
}
