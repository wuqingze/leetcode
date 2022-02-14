#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
   
    bool f1(int start, int cur, map<int, vector<int>> &g, set<int> &visited){
        visited.insert(cur);
        for(auto &i:g[cur]){
            if(start == i) return true;
            if(visited.find(i) == visited.end()){
                bool result =  f1(start, i, g, visited);
                if(result) return result;
            }
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> tmap;
        for(auto &l: prerequisites){
            tmap[l[1]].push_back(l[0]);
        }
        set<int> visited, path;
        for(auto itr=tmap.begin();itr!=tmap.end();itr++){
            bool loop = f1(itr->first, itr->first, tmap, visited);
            if(loop) return false;
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
