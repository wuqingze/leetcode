#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==1) return 1;

        sort(envelopes.begin(), envelopes.end(), [](const auto &o1, auto const &o2){
                if(o1[0]<o2[0]) return true;
                if(o1[0]==o2[0]) return o1[1]>o2[1];
                return false;
                });

        int len = 1;
        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1] > dp.back()){
                dp.push_back(envelopes[i][1]);
                len += 1;
            }else{
                int index = find(dp, len-1, envelopes[i][1]);
                dp[index] = envelopes[i][1];
            }
        }
        return len;
    }

    int find(vector<int> &dp, int end, int target){
        int start = 0;
        int mid;
        while(start<=end){
            mid = (end-start)/2 + start;
            if(dp[mid] == target){
                return mid;
            }else if(dp[mid]>target){
                if(mid == 0) return 0;
                if(dp[mid-1]<= target) return mid;
                end = mid-1;
            }else{
                start = mid +1;
            }
        }
        return end;
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
