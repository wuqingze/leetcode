#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int f(vector<int> &l, map<vector<int>, int> &dp){
        if(l.size() == 1) return l[0];
        if(l.size() == 2) return l[0]>l[1]?l[0]+l[0]*l[1]:l[1]+l[0]*l[1];
        if(dp.count(l) != 0){
            cout<<"--------"<<endl;
            return dp[l];
        }
        int n = l.size();
        int ret = -1;
        for(int i=0;i<n;i++){
            auto key = vector<int>(l.begin(), l.end());
            if(i==0){
                key.erase(key.begin());
                ret = max(ret, l[0]*l[1]+f(key, dp));
            }else if(i==n-1){
                key.erase(key.begin()+n-1);
                ret = max(ret, l[n-1]*l[n-2]+f(key,dp));
            }else{
                key.erase(key.begin()+i);
                ret = max(ret, l[i]*l[i-1]*l[i+1]+f(key, dp));
            }
        }
        dp[l] = ret;
        return dp[l];
    }

    int maxCoins(vector<int>& nums) {
        map<vector<int>, int> dp;
        return f(nums, dp);
    }
};

int main(int argc, char* argv[]){
    vector<int> nums(argc-1);
    for(int i=0;i<nums.size();i++){
        nums[i] = atoi(argv[i+1]);
    }
    Solution solution;
    auto ret = solution.maxCoins(nums);
    cout<<ret<<endl;
    return 0;
}
