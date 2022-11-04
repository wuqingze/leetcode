#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int n = strs.size();
        map<string, vector<string>> gmap;
        for(auto s:strs){
            string k = s;
            sort(k.begin(), k.end());
            gmap[k].push_back(s);
        }
        for(auto itr=gmap.begin();itr!=gmap.end();itr++){
            ret.push_back(itr->second);
        }
        return ret;
    }
};

int main(){

    Solution solution;
    vector<string> strs =  {"eat","tea","tan","ate","nat","bat"};
    auto ret = solution.groupAnagrams(strs);
    for(auto group:ret)
    {
        for(auto s:group){
            cout<<s<<",";
        }
        cout<<endl;
    }
    return 0;
}
