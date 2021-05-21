#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n+1);
        vector<vector<pair<int,int>>> graph(n+1);
        int res = 0;
        for(auto time:times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> list;
        list.push_back(k);
        int cnt = 0;
        while(not list.empty()){
            vector<int> tmp;
            for(auto index:list){
                visited[index] = true;
            }
            for(int index: list){
                cnt += 1;
                int t = 0;
                for(auto node:graph[index]){
                    if(not visited[node.first]){
                        tmp.push_back(node.first);
                        t = max(t, node.second);
                    }
                }
                res += t;
            }
            list = tmp;
        }
        return cnt==n?res:-1;
    }
};

int main(){
//    vector<vector<int>> times = {
//        {2,1,1}, {2,3,1}, {3,4,1}
//    };
//    int n = 4;
//    int k = 2
    vector<vector<int>> times = {
        {1,2,1}, {2,3,2}, {1,3,2}
    };
    int n = 3;
    int k = 1;
 ;
    Solution solution;
    auto res = solution.networkDelayTime(times, n, k);
    cout<<res<<endl;
    return 0;
}
