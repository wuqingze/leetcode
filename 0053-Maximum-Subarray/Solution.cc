#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxc(long long o1, long long o2) {
        if(o1<o2) return o2;
        else return o1;
    }

    long long minc(long long o1, long long o2){
        if(o1<o2) return o1;
        else return o2;
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<long long> presum(n);
        presum[0] = nums[0];
        for(int i=1;i<n;i++) presum[i] = presum[i-1]+nums[i];

        long long ret = presum[0];
        long long mn = 0;
        for(int i=0;i<n;i++){
            ret = maxc(ret, presum[i] - mn);
            mn = minc(mn, presum[i]);
        }
        return ret;
    }
};

int main(){
    Solution solution;
    //vector<int> nums = {5,4,-1,7,8};
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    auto ret = solution.maxSubArray(nums);
    cout<<ret<<endl;
    return 0;
}
