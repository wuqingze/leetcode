#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution{
    public:
        static string minWindow(string s, string t){
            if(s.empty() || t.empty()) return "";
            unordered_map<char, int> dictT;
            unordered_map<char, int> windowCounts;
            for(char c:t) dictT[c] = dictT.count(c)?dictT[c]+1:1;
            int required = dictT.size(), formed = 0, l=0, r=0;
            int ans[]= {-1, 0, 0};
            while(r<s.size()){
                char c = s[r];
                windowCounts[c] = windowCounts.count(c)?windowCounts[c]+1:1;
                if(dictT.count(c) && dictT[c] == windowCounts[c]) formed ++;

                while(l<=r &&  formed == required){
                    c = s[l];
                    if(ans[0] == -1 || r-l+1<ans[0]){
                        ans[0] = r-l+1;
                        ans[1] = l;
                        ans[2] = r;
                    }
                    windowCounts[c] -= 1;
                    if(dictT.count(c) && windowCounts[c]<dictT[c]) formed --;
                    l ++;
                }
                r++;
            }
            return s.substr(ans[1], ans[2]);
       }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        string s, t;
        args>>s>>t;
        string minStr = Solution::minWindow(s, t);
        cout<<"s: "<<s<<", t: "<<t<<", minStr: "<<minStr<<endl;
    }

    return 0;
}
