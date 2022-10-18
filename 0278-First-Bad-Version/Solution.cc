// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        int m;
        while(l<=h){
            m = l+(h-l)/2;
            if(isBadVersion(m)){
                if(m == 1) return 1;
                if(isBadVersion(m-1)){
                    h = m-1;
                }else{
                    return m;
                }
            }else{
                if(isBadVersion(m+1)){
                    return m+1;
                }else{
                    l = m+1;
                }
            }
        }
        return -1;
    }
};
