#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int> dp(n);
        vector<int> dp2(n);

        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        for(int i=n-3;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[0];
    }
};

int main(){
    Solution solution;
    //vector<int> nums = {2,7,9,3,1};
    vector<int> nums = {1,2,3,1};
    auto ret = solution.rob(nums);
    cout<<ret<<endl;
    return 0;
}
