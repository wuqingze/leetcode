#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto interval : intervals) {
            if (!q.empty() && q.top() <= interval[0]){
                q.pop();
            }
            q.push(interval[1]);
        }
        return q.size();
    }
};

int main(){
    Solution solution;
    vector<vector<int>> intervals = {{0,2},{1,3},{4,6},{5,7}};
    cout<<solution.minMeetingRooms(intervals)<<endl;
    return 0;
}
