#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        set<string> dp;
        set<string> match;
        int n = s.size();
        for(int i=0;i<=n-10;i++){
            auto t = s.substr(i, 10);
            if(dp.find(t) == dp.end()){
                dp.insert(t);
            }else{
                if(match.find(t) == match.end()){
                    match.insert(t);
                }
            }
        }
        for(auto item=match.begin(); item != match.end();item++){
            ret.push_back(*item);
        }
        return ret;
    }
};


int main(){
    string str;
    cin>>str;
    Solution solution;
    auto ret = solution.findRepeatedDnaSequences(str);
    for(int i=0;i<ret.size();i++) cout<<ret[i]<<endl;
    return 0;
}
