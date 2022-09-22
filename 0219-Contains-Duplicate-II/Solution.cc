class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> cnt;
        int n = nums.size();
        for(int i=0;i<=k and i<n;i++){
            if(cnt.find(nums[i]) == cnt.end()){
                cnt.insert(nums[i]);
            }else return true;
        }
        int i=0;
        int j=k+1;
        for(;j<n;j++){
            cnt.erase(nums[i]);
            i += 1;
            if(cnt.find(nums[j]) == cnt.end()){
                cnt.insert(nums[j]);
            }else{
                return true;
            }
        }
            
        return false;
    }
};
