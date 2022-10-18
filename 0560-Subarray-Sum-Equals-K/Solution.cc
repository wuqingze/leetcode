class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> cnt;
        cnt.insert({0,1});
        int n = nums.size();
        vector<int> presum(n);
        presum[0] = nums[0];
        if(nums[0] == 0) cnt[0] = 2;
        else cnt[nums[0]] = 1;
        int ret = k==nums[0]?1:0;
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
            if(cnt.find(presum[i]-k) != cnt.end()){
                ret += cnt[presum[i]-k];
            }
            if(cnt.find(presum[i]) == cnt.end()) cnt.insert({presum[i], 1});
            else cnt[presum[i]] += 1;
        }
        return ret;
    }
};
