#include <iostream>
#include <sstream>
using namespace std;

class Solution{

    public:
        static string longestPalindrome(string s) {
            int n = s.size();
            if(n==0) return "";

            int dp[n][n];
//            for(int i=0;i<n;i++)
//                for(int j=0;j<n;j++)
//                    if(i==j)dp[i][j]=1;else dp[i][j] = -1;
            int ans[] = {0,0,0};
            for(int i=n-1;i>=0;i--){
                for(int j=i;j<n;j++){
                    if(s[i] == s[j]){
                        if(i==j || i==j-1 || dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                            if(ans[0]<j-i+1){
                                ans[0] = j-i+1;
                                ans[1] = i;
                                ans[2] = j;
                            }
                        }else{
                            dp[i][j]=0;
                        }
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
            return s.substr(ans[1], ans[2]-ans[1]+1);
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        string pldStr = Solution::longestPalindrome(line);
        cout<<line<<endl;
        cout<<pldStr<<endl;;
        cout<<"--------------"<<endl;
    }
    return 0;
}
