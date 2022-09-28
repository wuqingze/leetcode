class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        if(n == 0) return {};
        if(n == 1) return {to_string(nums[0])};
        
        int s = 0;
        int i = 1;
        while(i<n){
            if(nums[i-1]+1 == nums[i]){
                i += 1;
            }else{
                if(s == i-1){
                    ret.push_back(to_string(nums[s]));
                }else{
                    ret.push_back(to_string(nums[s])+"->"+to_string(nums[i-1]));
                }
                s = i;
                i += 1;
            }
        }
        if(s == n-1){
                ret.push_back(to_string(nums[s]));
            }else{
                ret.push_back(to_string(nums[s])+"->"+to_string(nums[n-1]));
            }
        return ret;
    }
};
