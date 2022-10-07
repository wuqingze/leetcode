#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

class UF{
public:
    vector<int> root;
    vector<int> rank;

    UF(int n){
        root = vector<int>(n);
        for(int i=0;i<n;i++) root[i] = i;
        rank = vector<int>(n, 1);
    }

    int find(int i){
        if(i==root[i]) return i;
        root[i] = find(root[i]);
        return root[i];
    }

    void merge(int i, int j){
        int iroot = find(i);
        int jroot = find(j);
        if(rank[iroot]<=rank[jroot]){
            root[iroot] = jroot;
        }else{
            root[jroot] = iroot;
        }
        if(rank[iroot]==rank[jroot]){
            rank[jroot] += 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UF uf(10);
        unordered_map<string, int> emailids;
        unordered_map<string, string> emailnames;
        int id = 0;
        for(auto account: accounts){
            int n = account.size();
            string name = account[0];
            for(int i=1;i<n;i++){
                if(emailids.find(account[i]) == emailids.end()){
                    emailids.insert({account[i], id++});
                    emailnames.insert({account[i], name});
                }
                uf.merge(emailids[account[1]], emailids[account[i]]);
            }
        }
        unordered_map<int, vector<string>> mailgroup;
        for(auto ptr=emailids.begin();ptr!=emailids.end();ptr++){
            int id = uf.find(ptr->second);
            if(mailgroup.find(id) == mailgroup.end()){
                mailgroup[id].push_back(emailnames[ptr->first]);
                mailgroup[id].push_back(ptr->first);
            }else{
                mailgroup[id].push_back(ptr->first);
            }
        }
        vector<vector<string>> res;
        for(auto ptr=mailgroup.begin();ptr!=mailgroup.end();ptr++){
            sort(++ptr->second.begin(), ptr->second.end());
            res.push_back(ptr->second);
        }
        return res;
    }
};

int main(){
    string line;
    vector<vector<string>> accounts;
    while(getline(cin, line)){
        istringstream is(line);
        string t;
        vector<string> account; 
        while(is>>t) account.push_back(t);
        accounts.push_back(account);
    }
    Solution solution;
    auto res = solution.accountsMerge(accounts);
    for(auto &accounts: res){
        for(auto &account: accounts){
            cout<<account<<",";
        }
        cout<<endl;
    }
    return 0;
}
