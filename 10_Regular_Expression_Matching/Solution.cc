#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
    public:
        // dp t->true, f->false, u->untraced
        bool dpf(string s, string p, int i, int j, int n, int m, vector<vector<char>> &dp){
//            cout<<"i:"<<i<<",j:"<<j<<",n:"<<n<<",m:"<<m<<endl;
            if(j>=m) return i>=n?true:false;
            if(i>=n){
                return j+1<m?p[j+1]=='*'?dpf(s, p, i, j+2, n, m, dp):false:false;
            }
            if(dp[i][j] != 'u') return dp[i][j]=='t'?true:false;

            bool ret = false;
            if(p[j] == '.'){
                if(j+1<m && p[j+1]=='*'){
                    ret = dpf(s, p, i+1, j+2, n, m, dp) || dpf(s, p, i+1, j, n, m, dp) ||  dpf(s, p, i, j+2, n, m, dp);
                }else{
                    ret = dpf(s, p, i+1, j+1, n, m, dp);
                }
            }else{
                if(s[i] == p[j]){
                    if(j+1<m && p[j+1]=='*'){
                        ret = dpf(s, p, i, j+2, n, m, dp) || dpf(s, p, i+1, j, n, m, dp) || dpf(s, p, i+1, j+2, n, m, dp);
                    }else{
                        ret = dpf(s, p, i+1, j+1, n, m, dp);
                    }
                }
                else{
                    if(j+1<m && p[j+1]=='*') ret = dpf(s, p, i, j+2, n, m, dp);
                    else ret = false;
                }
            }
            dp[i][j] = ret?'t':'f';
            return ret;
        }

        bool isMatch(string s, string p){
            int n=s.size(), m=p.size();
            vector<vector<char>> dp(n, vector<char>(m, 'u'));
            return dpf(s, p, 0, 0, n, m, dp);
        }
};

int main(){
    string line;
    Solution solution;
    while(getline(cin, line)){
        istringstream is(line);
        string s;
        string p;
        cout<<line<<endl;
        is>>s;is>>p;
        bool ret = solution.isMatch(s, p);
        cout<<ret<<endl;
    }
    return 0;
}
