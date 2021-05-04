#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=2){
            vector<int> res(n);
            for(int i=0;i<n;i++) res[i] = i;
            return res;
        }

        vector<unordered_set<int>> neighbors(n);
        for(auto edge: edges){
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(neighbors[i].size() == 1){
                leaves.push_back(i);
            }
        }

        int remained = n;
        while(remained > 2){
            vector<int> newLeaves;
            for(auto leaf : leaves){
                int parent = *(neighbors[leaf].begin());
                neighbors[parent].erase(leaf);
                if(neighbors[parent].size() == 1){
                    newLeaves.push_back(parent);
                }
            }
            remained -= leaves.size();
            leaves = newLeaves;
        }

        return leaves;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges;
    int t;
    while(cin>>t){
        vector<int> tumple(2);
        tumple[0] = t;
        cin>>t;
        tumple[1] = t;
        edges.push_back(tumple);
    }
    Solution solution;
    auto res = solution.findMinHeightTrees(n, edges);
    for(auto i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
