\piclass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> tm;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(tm.find(nums[i]) == tm.end()){
                tm[nums[i]] = 1;
            }else{
                tm[nums[i]] += 1;
            }
        }
        vector<pair<int,int>> l;
        vector<int> ret;
        for(auto itr=tm.begin();itr!=tm.end();itr++){
            l.push_back({itr->first, itr->second});
        }
        sort(l.begin(), l.end(), [](const auto &o1, const auto &o2){
            return o1.second>o2.second;
        });
        for(int i=0;i<k;i++){
            ret.push_back(l[i].first);
        }
        
        return ret;
    }
};
