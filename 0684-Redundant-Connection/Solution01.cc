#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class UF{
public:
    vector<int> parent;
    vector<int> rank;

    UF(int n){
        parent = vector<int>(n);
        for(int i=0;i<n;i++) parent[i] = i;
        rank = vector<int>(n, 1);
    }

    int root(int i){
        if(i == parent[i]) return i;
        parent[i] = root(parent[i]);
        return parent[i];
    }

    bool connected(int i, int j){
        return root(i) == root(j);
    }

    void merge(int i, int j){
        int iroot = root(i);
        int jroot = root(j);

        if(rank[iroot]<=rank[jroot]){
            parent[iroot] = jroot;
        }else{
            parent[jroot] = iroot;
        }
        if(rank[iroot] == rank[jroot]){
            rank[jroot] += 1;
        }
    }

};

class Solution{
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            UF unionfind(n+1);
            for(auto &edge:edges){
                if(unionfind.connected(edge[0], edge[1])){
                    return edge;
                }
                unionfind.merge(edge[0], edge[1]);
            }
            return {};
        }
};

int main(){
    string line;
    Solution slt;
    while(getline(cin, line)){
        istringstream is(line);
        int num;
        int index = 0;
        vector<vector<int>> edges;
        while(is>>num){
            if(index%2==0){
                edges.push_back(vector<int>(2));
                edges[edges.size()-1][0] = num;
            }else{
                edges[edges.size()-1][1] = num;
            }
            index ++;
        }
        auto result = slt.findRedundantConnection(edges); 
        cout<<line<<endl;
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    return 0;
}
