class Solution {
public:
    bool isSubsequence(string s, string t) {
       int n = s.size();
        int m = t.size();
        int i=0;
        int j=0;
        while(i<n and j<m){
            if(s[i] == t[j]){
                i += 1;
                j += 1;
            }else{
                j += 1;
            }
        }
        return i==n;
    }
};
