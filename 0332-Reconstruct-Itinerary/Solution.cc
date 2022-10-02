#include <iostream>
#include <algorithm>
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
        vector<pair<string, string>> tt;
        vector<string> ret;

        map<string, multiset<string>> g;
        int n = tickets.size();

        for(auto ticket:tickets){
            if(g.find(ticket[0]) == g.end()){
                g[ticket[0]] = {ticket[1]};
            }else{
                g[ticket[0]].insert(ticket[1]);
            }
        }

        auto tos = g["JFK"];
        if(tos.size() == 1){
            ret.push_back("JFK");
            ret.push_back(*(tos.begin()));
            g.erase(g.find("JFK"));
            f(g, *(tos.begin()), ret);
        }else{
            ret.push_back("JFK");
            for(auto itr=tos.begin();itr!=tos.end();itr++){
                ret.push_back(*itr);
                g["JFK"].erase(g["JFK"].find(*itr));
                bool t = f(g, *itr, ret);
                if(t) break;
                else{
                    ret.pop_back();
                    g["JFK"].insert(*itr);
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
