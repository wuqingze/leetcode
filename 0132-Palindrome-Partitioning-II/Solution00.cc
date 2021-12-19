#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> pldr = vector<vector<bool>>(n, vector<bool>(n, false));
        for(int i=0;i<n;i++) pldr[i][i] = true;
        vector<int> cut = vector<int>(n);
        for(int i=0;i<n;i++) cut[i] = i;

        for(int j=0;j<n;j++){
            int mn = cut[j];
            for(int i=0;i<=j;i++){
                if(s[i] == s[j] and (i+1>j-1 or pldr[i+1][j-1])){
                    pldr[i][j] = true;
                    mn = i==0?0:min(mn, cut[i-1]+1);
                }
            }
            cut[j] = mn;
        }
        return cut[n-1];
    }
};
int main(int argc, char* argv[]){
    string s(argv[1]);
    cout<<Solution().minCut(s)<<endl;
    return 0;
}
