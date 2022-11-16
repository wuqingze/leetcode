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

        vector<int> dp1(n);
        vector<int> dp2(n);

        dp1[n-1] = nums[n-1];
        dp1[n-2] = nums[n-2];
        for(int i=n-3;i>=1;i--){
            dp1[i] = max(nums[i]+dp1[i+2], dp1[i+1]);
        }

        dp2[n-2] = nums[n-2];
        dp2[n-3] = nums[n-3];
        for(int i=n-4;i>=0;i--){
            dp2[i] = max(nums[i]+dp2[i+2], dp2[i+1]);
        }


        return max(dp1[1], dp2[0]);
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
