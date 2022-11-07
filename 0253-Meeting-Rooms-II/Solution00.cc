#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 1;
        multiset<int> tset;
        sort(intervals.begin(), intervals.end(),[](auto o1, auto o2){ return o1[0]<o2[0];});
        tset.insert(intervals[0][1]);
        for(int i=1;i<n;i++){
            if(intervals[i][0] < *(tset.begin())){
                tset.insert(intervals[i][1]);
            }else{
                tset.erase(tset.begin());
                tset.insert(intervals[i][1]);
            }
        }
        return tset.size();
    }
};

int main(){
    Solution solution;
    vector<vector<int>> intervals = {{0,2},{1,3},{4,6},{5,7}};
    cout<<solution.minMeetingRooms(intervals)<<endl;
    return 0;
}
