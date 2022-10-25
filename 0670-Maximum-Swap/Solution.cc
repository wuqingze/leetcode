class Solution {
public:
    int maximumSwap(int num) {
        string s= to_string(num);
        int n = s.size();
        for(int i=0;i<n-1;i++){
            int k = i;
            for(int j=i+1;j<n;j++){
                if(s[j]>=s[k]) k = j;
            }
            if(s[k]!=s[i]) {swap(s[i],s[k]);break;}
        }
        return atoi(s.c_str());
    }
};
