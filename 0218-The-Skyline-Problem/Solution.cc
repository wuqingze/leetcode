#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        if(n == 1) return {{buildings[0][0], buildings[0][2]}, {buildings[0][1], 0}};
        vector<vector<int>> blds;
        for(auto &build: buildings){
            blds.push_back({build[0], build[2], 0});
            blds.push_back({build[1], build[2], 1});
        }
        sort(blds.begin(), blds.end(), [](auto &o1, auto &o2){
                if(o1[0] < o2[0]) return true;
                if(o1[0] == o2[0]){
                    if(o1[2] == o2[2]){
                        if(o1[2] == 0) return o1[1]>o2[1];
                        else return o1[1]<o2[1];
                    }else{
                        return o1[2]<o2[2];
                    }
                }
                return false;
                });
        vector<vector<int>> ret;
        n = blds.size();
        multiset<int> m;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(blds[i][2] == 0){
                if(flag){
                    ret.push_back({blds[i][0], blds[i][1]});
                    m.insert(blds[i][1]);
                    flag = false;
                    continue;
                }
                if(blds[i][1] > *(m.rbegin())){
                    ret.push_back({blds[i][0], blds[i][1]});
                }
                m.insert(blds[i][1]);
            }else{
                m.erase(m.find(blds[i][1]));
                if(m.size() == 0){
                    flag = true;
                    ret.push_back({blds[i][0], 0});
                }else{
                    if(blds[i][1] > *(m.rbegin())){
                        ret.push_back({blds[i][0], *(m.rbegin())});
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    int n = (argc-1)/3;
    vector<vector<int>> buildings(n);
    for(int i=0;i<n;i++){
        buildings[i] = {atoi(argv[i*3+1]),atoi(argv[i*3+2]),atoi(argv[i*3+3])};
    }
    Solution solution;
    auto ret = solution.getSkyline(buildings);
    for(auto &item:ret){
        cout<<"["<<item[0]<<","<<item[1]<<"],";
    }
    cout<<endl;
    return 0;
}
