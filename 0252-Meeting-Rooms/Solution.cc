#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        multiset<pair<int,int>> tree;
        int n = intervals.size();
        if(n<2) return true;
        tree.insert({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            auto nxt = tree.lower_bound({intervals[i][0], intervals[i][1]});
            if(nxt == tree.end()){
                auto prv = tree.rbegin();
                if(prv->second >= intervals[i][0]) return false;
            }else if(nxt == tree.begin()){
                if(intervals[i][1] >= nxt->first) return false;
            }else{
                auto prv = prev(nxt);
                if(prv->second >= intervals[i][0] or nxt->first <= intervals[i][1]) 
                    return false;
            }
            tree.insert({intervals[i][0], intervals[i][1]});
        }
        return true;
    }
};

int main(){
//    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    vector<vector<int>> intervals = {{7,10},{2,4}};
    Solution solution;
    cout<<solution.canAttendMeetings(intervals)<<endl;
    return 0;
}
