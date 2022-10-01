#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    bool f(map<string, multiset<string>> &g, string from, vector<string> &ret){
        if(g.size() == 0){
            return true;
        }
        if(g.find(from) == g.end() or g[from].size() == 0){
            return false;
        }
        auto tos = g[from];
        if(tos.size() == 1){
            g.erase(g.find(from));
            ret.push_back(*(tos.begin()));
            bool t = f(g, *(tos.begin()), ret);
            if(not t){
                g.insert({from, tos});
                ret.pop_back();
            }
            return t;
        }else{
            for(auto itr=tos.begin(); itr!=tos.end();itr++){
                g[from].erase(g[from].find(*itr));
                ret.push_back(*itr);
                bool t = f(g, *itr, ret);
                if(t){
                    return true;
                }else{
                    g[from].insert(*itr);
                    ret.pop_back();
                }
            }
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ret;
        map<string, multiset<string>> g;
        int n = tickets.size();
        for(int i=0;i<n;i++){
            if(g.find(tickets[i][0]) == g.end()){
                g[tickets[i][0]] = {tickets[i][1]};
            }else{
                g[tickets[i][0]].insert(tickets[i][1]);
            }
        }
        for(int i=0;i<n;i++){
            auto iti = tickets[i];
            ret.push_back(iti[0]);
            ret.push_back(iti[1]);
            auto tos = g[iti[0]];
            if(tos.size() == 1){
                g.erase(g.find(iti[0]));
            }else{
                g[iti[0]].erase(g[iti[0]].find(iti[1]));
            }
            bool t = f(g, iti[1], ret);
            if(t){
                break;
            }else{
                ret.pop_back();
                ret.pop_back();
                if(tos.size() == 1){
                    g[iti[0]] = {iti[1]};
                }else{
                    g[iti[0]].insert(iti[1]);
                }
            }
        }
        return ret;
    }
};


int main(){
    vector<vector<string>> tickets;
    string t;
    string t1;
    while(cin>>t){
        cin>>t1;
        tickets.push_back({t, t1});
    }
    Solution solution;
    auto ret = solution.findItinerary(tickets);
    for(auto tic:ret){
        cout<<tic<<",";
    }
    cout<<endl;
    return 0;;
}
