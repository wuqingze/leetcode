class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m*n;
        int l=100000;
        int w=100000;
        for(auto item: ops){
            l = min(l, item[0]);
            w = min(w, item[1]);
        }
        return l*w;
    }
};
