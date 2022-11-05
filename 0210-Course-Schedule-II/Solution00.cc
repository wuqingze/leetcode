#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> weights(n, 0);
        vector<vector<int>> graph(n);
        vector<int> zlist;
        vector<int> tlist;
        vector<int> res;
        
        for(auto request:prerequisites){
            weights[request[0]] += 1;
            graph[request[1]].push_back(request[0]);
        }

        for(int i=0;i<n;i++){
            if(weights[i] == 0) zlist.push_back(i);
        }
        while(not zlist.empty()){
            for(int c:zlist){
                res.push_back(c);
                for(int i:graph[c]){
                    weights[i] -= 1;
                    if(weights[i] == 0){
                        tlist.push_back(i);
                    }
                }
            }
            zlist = tlist;
            tlist.clear();
        }
        for(int w:weights) if(w!=0) return {};
        return res;
    }
};

int main(){
    int numCourses;
    cin>>numCourses;
    vector<vector<int>> prerequisites;
    int t;
    while(cin>>t){
        int t1;
        cin>>t1;
        prerequisites.push_back({t,t1});
    }
    Solution solution;
    for(auto &l:prerequisites){
        cout<<"["<<l[0]<<","<<l[1]<<"],";
    }
    auto result = solution.findOrder(numCourses, prerequisites);
    cout<<endl;
    for(auto &i:result)
        cout<<i<<" ";
    return 0;
}
