class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        map<int, int> cnt;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(cnt.find(nums[i]) == cnt.end()){
                cnt[nums[i]] = 1;
            }else cnt[nums[i]] += 1;
        }
        for(auto itr=cnt.begin();itr!=cnt.end();itr++){
            if(itr->second>n/3) ret.push_back(itr->first);
        }
        return ret;
    }
};
