#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx = 0;
        map<int, int> xmap;
        map<int, int> ymap;
        for(auto point: points){
            if(xmap.find(point[0]) != xmap.end()){
                xmap[point[0]] += 1;
            }else{
                xmap[point[0]] =1;
            }

            if(ymap.find(point[1]) != ymap.end()){
                ymap[point[1]] += 1;
            }else{
                ymap[point[1]] = 1;
            }


            mx = max(mx, xmap[point[0]]);
            mx = max(mx, ymap[point[1]]);

        }
        int n = points.size();
        for(int i=0;i<n;i++){
            auto base = points[i];
            vector<pair<int, int>> tmp;
            for(int j=0;j<n;j++){
                if(i != j){
                    if(points[j][0] != base[0] and points[j][1] != base[1]){
                        tmp.push_back({points[j][0] - base[0], points[j][1] - base[1]});
                    }
                }
            }
            int tn = tmp.size();
            int tmx = tn==0?1:2;
            for(int k =0;k<tn-1;k++){
                int kk = 2;
                for(int l=k+1;l<tn;l++){
                    if(tmp[k].first*tmp[l].second == tmp[k].second*tmp[l].first){
                        kk += 1;
                    }
                }
                tmx = max(tmx, kk);
            }

            mx = max(mx, tmx);
        }
        return mx;
    }
};

int main(){
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
