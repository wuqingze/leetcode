class Solution {
public:
    vector<int> indexs;
    int n;
    int mx;
    Solution(vector<int>& w) {
        n = w.size();
        indexs = vector<int>(n);
        indexs[0] = w[0];
        for(int i=1;i<n;i++){
            indexs[i] = indexs[i-1]+w[i];
        }
        mx = indexs[n-1];
    }
    
    int f(int i){
        int l=0;
        int h = n-1;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(indexs[m] == i){
                return m+1;
            }else if(indexs[m] > i){
                if(m == 0) return 0;
                if(indexs[m-1] <= i) return m;
                else{
                    h = m-1;
                }
            }else{
                if(m == n-1) return m;
                if(indexs[m+1] >i) return m+1;
                else{
                    l = m+1;
                }
            }
        }
        return -1;
    }
    
    int pickIndex() {
        //srand(time(NULL));
        return f(rand()%mx);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
