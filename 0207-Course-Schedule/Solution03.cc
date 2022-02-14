#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> zeros;
        map<int, int> rudu;
        map<int, vector<int>> edges;
        for(int i=0;i<numCourses; i++){
            zeros.insert(i);
            rudu[i] = 0;
        }
        for(auto edge:prerequisites){
            auto ptr = zeros.find(edge[0]);
            if(ptr != zeros.end()) zeros.erase(ptr);
            rudu[edge[0]] += 1;
            edges[edge[1]].push_back(edge[0]);
        }
        while(not zeros.empty()){
            auto ptr = zeros.begin();
            int node = *(ptr);
            zeros.erase(ptr);
            for(auto next:edges[node]){
                rudu[next] -= 1;
                if(rudu[next] == 0) zeros.insert(next);
            }
        }

        for(auto ptr=rudu.begin();ptr!=rudu.end();ptr++){
            if(ptr->second > 0){
                return false;
            }
        }
        return true;
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
    cout<<endl<<solution.canFinish(numCourses, prerequisites);
    return 0;
}
