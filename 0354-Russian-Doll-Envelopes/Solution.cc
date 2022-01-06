#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n == 1) return 1;
        sort(envelopes.begin(), envelopes.end(), [](const auto &o1, const auto &o2){
                if(o1[0]<o2[0]) return true;
                if(o1[0]==o2[0]) return o1[1]<o2[1];
                return false;
                });
        int i=0;
        int key = envelopes[0][0];
        while(i<n and envelopes[i][0] == key) i++;
        if(i==n) return 1;
        else i-=1;
        vector<int> dp(n, 1);
        while(i<n-1){
            key = envelopes[i+1][0];
            int j = i+1;
            while(j<n and envelopes[j][0] == key){
                for(int k=0;k<=i;k++){
                    if(envelopes[k][1] < envelopes[j][1]){
                        dp[j] = max(dp[j], dp[k]+1);
                    }
                }
                j+=1;
            }
            i = j-1;
        }
        int ret = 0;
        for(auto &num:dp) ret = max(ret, num);
        return ret;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution solution;
    vector<vector<int>> envelopes((argc-1)/2, vector<int>(2));
    for(int i=0;i<(argc-1)/2;i++){
        envelopes[i] = {atoi(argv[i*2+1]), atoi(argv[i*2+2])};
    }
    auto ret = solution.maxEnvelopes(envelopes);
    cout<<ret<<endl;
    return 0;
};
