#include <map>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool f(vector<bool> &visited, vector<bool> &path, map<int, vector<int>> &graph, int course, stack<int> &result){
        if(visited[course]) return false;
        visited[course] = true;
        path[course] = true;
        for(auto &next:graph[course]){
            if(path[next]){
                path[course] = false;
                return true;
            }
            if(not visited[next]){
                bool t = f(visited, path, graph, next, result);
                if(t){
                    path[course] = false;
                    return true;
                }
            }
        }
        path[course] = false;
        result.push(course);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        stack<int> result;
        map<int, vector<int>> graph;
        for(auto &item:prerequisites){
            graph[item[1]].push_back(item[0]);
        }
        for(auto itr=graph.begin(); itr != graph.end(); itr++){
            bool isLoop = f(visited, path, graph, itr->first, result);
            if(isLoop){
                return {};
            }
        }
        vector<bool> preCourses(numCourses, false);
        vector<int> res(numCourses);
        int i = 0;
        while(not result.empty()){
            preCourses[result.top()] = true;
            res[i++] = result.top();
            result.pop();
        }
        for(int j=0;j<numCourses; j++){
            if(not preCourses[j]){
                res[i++] = j;
            }
        }
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
