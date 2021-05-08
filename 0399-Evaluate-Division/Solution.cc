#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class UF{
public:
    vector<pair<int, double>> root;

    UF(int n){
        root = vector<pair<int, double>>(n);
        for(int i=0;i<n;i++){
            root[i] = {i, 1};
        }
    }

    bool connected(int i, int j){
        return find(i).first == find(j).first;
    }

    pair<int, double> find(int i){
        if(i==root[i].first) return root[i];
        auto rootpair = find(root[i].first);
        root[i].first = rootpair.first;
        root[i].second = root[i].second*rootpair.second;
        return root[i];
    }

    void merge(int i, int j, double value){
        auto iroot = find(i);
        auto jroot = find(j);
        root[jroot.first].first = iroot.first;
        root[jroot.first].second = iroot.second*value/jroot.second;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        UF uf(2*n);
        int no=0;
        unordered_map<string, int> indexs;

        for(int i=0;i<n;i++){
            auto equation = equations[i];
            if(indexs.find(equation[0]) == indexs.end()){
                indexs.insert({equation[0], no++});
            }
            if(indexs.find(equation[1]) == indexs.end()){
                indexs.insert({equation[1], no++});
            }
            uf.merge(indexs[equation[0]], indexs[equation[1]], values[i]);
        }
        n = queries.size();
        vector<double> res(n);
        for(int i=0;i<n;i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if(indexs.find(a) != indexs.end() and indexs.find(b) != indexs.end()
                    and uf.connected(indexs[a], indexs[b]) ){
                auto iroot = uf.find(indexs[queries[i][0]]);
                auto jroot = uf.find(indexs[queries[i][1]]);
                res[i] = jroot.second/iroot.second;
            } else{
                res[i] = -1;
            }
        }
        return res;
    }
};

int main(){
    string line;
    getline(cin,line);
    istringstream is(line);
    vector<vector<string>> equations;
    string t1;
    string t2;
    while(is>>t1 and is>>t2){
        equations.push_back({t1, t2});
    }
    double t3;
    getline(cin, line);
    is = istringstream(line);
    vector<double> values;
    while(is>>t3){
        values.push_back(t3);
    }
    getline(cin, line);
    is = istringstream(line);
    vector<vector<string>> queries;
    while(is>>t1 and is>>t2){
        queries.push_back({t1, t2});
    }
    Solution solution;
    auto res = solution.calcEquation(equations, values, queries);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
