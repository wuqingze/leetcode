#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution{
    public:
        static string minWindow(string s, string t){
            if(s.empty() || s.size()<t.size()) return "";

            unordered_map<char, int> window;
            for_each(t.begin(), t.end(), [&window](char c){window.insert({c, 0});});
            int i=0, j=0, n = t.size(), count = 0;
            for(;j<s.size() && count<n;j++)
                if(window.count(s[j]) && window[s[j]] == 0){count += 1; window[s[j]] += 1;}
            if(j==n) return "";

            int ansi=i, ansj=j;
            int min = j-i+1;
            while(j<s.size()){
                char t = s[i];
                while(i<s.size() && t==s[i]) i++;
                j+=1;
                if(min>j-i+1){ ansi=i; ansj=j; min=j-i+1;}
            }
            return s.substr(ansi, ansj);
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
