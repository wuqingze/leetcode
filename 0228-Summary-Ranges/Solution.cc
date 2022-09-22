class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int s = 0;
        int n = nums.size();
        int i=0;
        while(i<n){
            if(i==n-1){
                if(i==s){
                    ret.push_back(to_string(nums[i]));
                }else{
                    ret.push_back(to_string(nums[s])+"->"+to_string(nums[i]));
                }
                break;
            }
            if(nums[i]+1 == nums[i+1]){
                i = i+1;
            }else{
                if(i==s){
                    ret.push_back(to_string(nums[i]));
                }else{
                    ret.push_back(to_string(nums[s])+"->"+to_string(nums[i]));
                }
                s = i+1;
                i = i+1;
            }
        }
        return ret;
    }
};
