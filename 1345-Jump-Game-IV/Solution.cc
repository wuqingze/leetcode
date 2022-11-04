#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> vmap;
        for(int i=0;i<n;i++){
            vmap[arr[i]].push_back(i);
        }

        set<int> visited;
        vector<int> cList;
        vector<int> tList;
        visited.insert(n-1);
        cList.push_back(n-1);
        int ret = 0;
        bool flag = true;
        while(flag){
            for(int c:cList){
                if(c == 0){
                    flag = false;
                    break;
                }
                if(c-1>=0 and visited.find(c-1) == visited.end()){
                    visited.insert(c-1);
                    tList.push_back(c-1);
                }
                if(c+1<n and visited.find(c+1) == visited.end()){
                    visited.insert(c+1);
                    tList.push_back(c+1);
                }
                for(auto i:vmap[arr[c]]){
                    if(visited.find(i) == visited.end()){
                        visited.insert(i);
                        tList.push_back(i);
                    }
                }
            }
            if(flag){
                ret += 1;
                cList = tList;
                tList.clear();
            }
        }
        return ret;
    }
};

int main(){
    Solution solution;
    //vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    //vector<int> arr = {1};
    vector<int> arr = {7,6,9,6,9,6,9,7};
    auto ret = solution.minJumps(arr);
    cout<<ret<<endl;
    return 0;
}
