#include <iostream>
#include <vector>

using namespace std;
class UF{
public:
    vector<int> root;
    vector<int> rank;

    UF(){
        root = vector<int>(100);
        rank = vector<int>(100, 0);
        for(int i=0;i<100;i++) root[i] = i;
    }

    int find(int i){
        if(root[i] == i) return i;
        root[i] = find(root[i]);
        return root[i];
    }

    void merge(int i, int j){
        int ir = find(i);
        int jr = find(j);

        if(rank[ir] <= rank[jr]){
            root[ir] = jr;
        }else{
            root[jr] = ir;
        }
        if(rank[ir] == rank[jr]){
            rank[jr] += 1;
        }
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        UF uf;
        int n = graph.size();
        for(int i=0;i<n;i++){
            auto l = graph[i];
            int m = l.size();
            if(m>0){
                for(int j=1;j<m;j++){
                    uf.merge(l[0], l[j]);
                }
                if(uf.find(i) == uf.find(l[0])) return false;
            }
        }
        return true;
    }
};

int main(){
    //vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    Solution solution;
    auto res = solution.isBipartite(graph);
    cout<<res;
    return 0;
}
