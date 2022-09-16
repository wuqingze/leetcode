#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    tuple<int, int,int> slope(pair<int, int> p1, pair<int, int> p2){
        int y = p2.second - p1.second;
        int x = p2.first - p1.first;
        if(x == 0) return {p1.first, 0, -1};
        if(y == 0) return {0, 
        return {};
    }

    int maxPoints(vector<vector<int>>& points) {
 //       int n = points.size();
 //       map<pair<int, int>, int> countMap;
 //       for(int i=0;i<n;i++){
 //           auto X = points[i];
 //           for(int j=i+1;j<n;j++){
 //               auto Y = points[j];
 //               double xielv = ((double)X[0] - (double)Y[0])/((double) X[1] - (double) Y[1]);
 //               if(countMap[xielv] == 0) countMap[xielv] = 1;
 //               else countMap[xielv] += 1;
 //           }
 //       }
 //       int mx = -1;
 //       for(auto ptr=countMap.begin();ptr!=countMap.end();ptr++){
 //           if(ptr->second>mx) mx = ptr->second;
 //       }
 //       return mx;
        return 0;
    }
};

int main(){
    map<vector<int>, int> vmap;
    vmap[{1,2,3}] = 1;
    cout<<vmap[{1,2,3}]<<endl;
    cout<<vmap[{2,2,3}]<<endl;
    return 0;
    map<pair<int, int>, int> intmap;
    intmap[{1,2}] = 1;
    cout<<intmap[{1,2}]<<endl;
    return 0;

    int x, y;
    vector<vector<int>> points;
    while(cin>>x>>y){
        points.push_back({x, y});
    }
    Solution s;
    auto ret = s.maxPoints(points);
    cout<<ret<<endl;
    return 0;
}
