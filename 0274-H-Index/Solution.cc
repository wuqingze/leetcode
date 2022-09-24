class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int h;
        for(int i=0;i<n;i++){
            h = n-i-1;
            if(citations[i]>h) return h+1;
        }
        return 0;
    }
};
