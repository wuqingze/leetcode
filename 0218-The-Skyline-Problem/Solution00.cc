#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a[1] < 0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
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
