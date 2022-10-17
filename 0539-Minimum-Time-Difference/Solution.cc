class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int day = 24*60;
        int n = timePoints.size();
        if(n>day) return 0;
        vector<int> minutes(n);
        for(int i=0;i<n;i++){
            auto point = timePoints[i];
            int h = atoi(point.substr(0,2).c_str());
            int m = atoi(point.substr(3,2).c_str());
            minutes[i] = m+h*60;
        }
        sort(minutes.begin(), minutes.end());
        int ret = day;
        for(int i=0;i<n-1;i++){
            ret = min(ret, minutes[i+1]-minutes[i]);
            if(ret == 0) return 0;
        }
        ret = min(ret, day-minutes[n-1]+minutes[0]);
        return ret;
    }
};
