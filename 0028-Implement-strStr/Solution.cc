class Solution {
public:
    bool b(string &s, int i, int j, string &s2){
        int t=i;
        while(t<=j){
            if(s[t] != s2[t-i]) return false;
            t += 1;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m = needle.size();
        if(n<m) return -1;
        if(m==0) return 0;
        
        int i=0, j=m-1;
        while(j<n){
            if(b(haystack, i, j, needle)) return i;
            i+= 1;
            j+=1;
        }
        return -1;
    }
};
