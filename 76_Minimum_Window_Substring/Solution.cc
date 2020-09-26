#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution{
    public:
        static string minWindow(string s, string t){
            if(s.empty() || t.empty() || s.size()<t.size()) return "";
            unordered_map<char, int> tmap;
            for_each(t.begin(), t.end(), [&tmap](char c){
                    if(tmap.count(c)) { 
                        tmap[c] += 1;}
                    else{
                        tmap[c] = 1;
                    }
            });
            return "";
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
