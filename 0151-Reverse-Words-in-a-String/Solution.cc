class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n = s.size();
        while(i<n and s[i] == ' ') i+= 1;
        int j = i;
        string ret = "";
        while(i<n){
            while(j<n and s[j] != ' ') j+=1;
            ret = s.substr(i, j-i) +" "+ ret;
            i = j;
            while(i<n and s[i] == ' ') i+=1;
            j = i;
        }
        return ret.substr(0, ret.size()-1);
    }
};
