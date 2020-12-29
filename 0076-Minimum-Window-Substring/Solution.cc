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
            unordered_map<char, int> windowCount;
            for_each(t.begin(), t.end(), [&dictT](char c){dictT[c] = dictT.count(c)?dictT[c]+1:1;});

            int l=0, r=0, ans[]={-1, 0,0}, required=dictT.size(), formed=0;
            while(r<s.size()){
                char c = s[r];
                windowCount[c] += 1;
                if(dictT.count(c) && dictT[c] == windowCount[c]) formed +=1;

                while(l<=r && required == formed){
                    c = s[l];
                    windowCount[c] -=1;
                    if(ans[0]==-1 || ans[0]>r-l+1){
                        ans[0] = r-l+1;
                        ans[1] = l;
                        ans[2] = r;
                    }

                    if(dictT.count(c) && dictT[c] > windowCount[c]) formed -=1;
                    l += 1;
                }
                r++;
            }
            return ans[0]==-1?"":s.substr(ans[1], ans[2]-ans[1]+1);
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
