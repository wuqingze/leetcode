class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int,int>> t(n);
        for(int i=0;i<n;i++){
             t[i] = {score[i], i};
        }
        sort(t.begin(), t.end(), [](auto const &o1,auto const &o2){
           return o1.first>o2.first; 
        });

        for(int i=0;i<n;i++){
            
            if(i == 0){
                ans[t[i].second] ="Gold Medal";
            }else if(i == 1){
                ans[t[i].second] ="Silver Medal";
            }else if(i == 2){
                ans[t[i].second] ="Bronze Medal";
            }else{
                ans[t[i].second] = to_string(i+1);
            }
        }
        return ans;
    }
};
