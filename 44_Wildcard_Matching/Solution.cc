#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        static bool f(int i, int j, int n, int m, vector<vector<char>> &dp, string &s, string &p){
            cout<<i<<" "<<j<<endl;
            if(i >=n){
                if(j>=m) return true;
                if(p[j] == '*') return f(i, j+1, n, m, dp, s, p);
                else return false;
            }
            if(j>=m) return false;
            if(dp[i][j] != -1) return dp[i][j]==0?false:true;

            bool t = false;
            if(s[i] == p[j]) t  = f(i+1, j+1, n, m, dp, s, p);
            else if(p[j] == '?') t = f(i+1, j+1, n, m, dp, s, p);
            else if(p[j] == '*') t = f(i+1, j, n, m, dp, s, p) || f(i+1, j+1, n, m, dp, s, p) || f(i, j+1, n, m, dp, s, p);
            else t = 0;
            dp[i][j] = t?1:0;
            return t;
        }

        static bool isMatch(string s, string p){
            int n = s.size(), m=p.size();
            vector<vector<char>> dp(n, vector<char>(m, -1));
            return f(0, 0, n, m, dp, s, p);
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        int mid = line.find(' ');
        string s = line.substr(0, mid);
        string p = line.substr(mid+1, line.size()-mid-1);
        cout<<line<<endl;
        cout<<Solution::isMatch(s, p)<<endl<<endl;
    }
    return 0;
}
