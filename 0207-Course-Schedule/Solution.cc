#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool f(set<int> &visited, set<int> &path, map<int, vector<int>> &tmap, 
          int start){
        visited.insert(start);
        path.insert(start);
        for(auto i: tmap[start]){
            if(visited.find(i) == visited.end()){
                bool result = f(visited, path, tmap, i);
                path.erase(start);
                return result;
            }else{
                if(path.find(i) != path.end()){
                    path.erase(start);
                    return true;
                }
            }
        }
        path.erase(start);
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> tmap;
        for(auto &l: prerequisites){
            tmap[l[1]].push_back(l[0]);
        }
        set<int> visited, path;
        for(auto itr=tmap.begin();itr!=tmap.end();itr++){
            bool loop = f(visited, path, tmap, itr->first);
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
