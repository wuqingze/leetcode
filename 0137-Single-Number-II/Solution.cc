class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> tmap;
        for(int i=0;i<n;i++){
            tmap[nums[i]] = tmap.find(nums[i])==tmap.end()?1:tmap[nums[i]]+1;
        }
        for(auto ptr=tmap.begin(); ptr != tmap.end(); ptr++)
            if(ptr->second == 1)
                return ptr->first;
        return 0;
    }
};
