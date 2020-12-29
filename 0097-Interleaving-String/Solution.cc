#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class Solution {
public:
    static bool f(int i, int j, int n, int m, vector<vector<char>> &dp, string &s1, string &s2, string &s3){
//        if(i+j==``m+n) return true;
        if(i==n){
            while(j<m){
                if(s2[j] != s3[i+j]) return false;
                j++;
            }
            return true;
        }
        if(j==m){
            while(i<n){
                if(s1[i] != s3[i+j]) return false;
                i++;
            }
            return true;
        }
        if(dp[i][j] != 'u') return dp[i][j]=='t'?true:false;

        bool ret = false;
        if(s1[i] == s3[i+j]){
            if(s2[j] == s3[i+j]){
                ret = f(i+1, j, n, m, dp, s1, s2, s3) || f(i, j+1, n, m, dp, s1, s2, s3);
            }else{
                ret= f(i+1, j, n, m, dp, s1, s2, s3);
            }
        }else{
            if(s2[j] == s3[i+j]){
                ret= f(i, j+1, n, m, dp, s1, s2, s3);
            }else{
                ret = false;
            }
        }
        dp[i][j] = ret?'t':'f';
        return ret; 
    }

    static bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m=s2.size();
        if(n+m != s3.size()) return false;
        vector<vector<char>> dp(n, vector<char>(m, 'u'));
        return f(0, 0, n, m, dp, s1, s2, s3);
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        string s1, s2, s3;
        is>>s1>>s2>>s3;
        auto ret = Solution::isInterleave(s1, s2, s3);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
