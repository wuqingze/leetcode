#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    string getKey(int x1, int y1, int x2, int y2){
        int y1_y2 = y1-y2;
        int x1_x2 = x1-x2;
        if(y1_y2 < 0 and x1_x2 < 0){
            y1_y2 = 0-y1_y2;
            x1_x2 = 0-x1_x2;
        }

        string a = [](int x1, int y1, int x2, int y2)->string{
            int y = y1-y2;
            int x = x1-x2;
            if(y<0 and x<0){
                y = 0-y;
                x = 0-x;
            }
            if(x == 0){
                return "*/"+std::to_string(x1); 
            }else{
                if(y%x == 0){
                    return std::to_string(y/x)+"/1";
                }else{
                    return std::to_string(y)+string("/")+std::to_string(x);
                }
            }
        }(x1, y1, x2, y2);

        string b = [](int x1, int y1, int x2, int y2)->string{
            int y = y1*(x1-x2) - x1*(y1-y2);
            int x = x1-x2;
            if(x == 0){
                return "*/"+std::to_string(x1); 
            }else{
                if(y%x == 0){
                    return std::to_string(y/x)+"/1";
                }else{
                    return std::to_string(y)+string("/")+std::to_string(x);
                }
            }
        }(x1, y1, x2, y2);

        return a+"x+"+b;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<2) return 1;
        map<string, set<int>> tmap;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                auto key = getKey(points[i][0], points[i][1], points[j][0], points[j][1]);
                tmap[key].insert(i);
                tmap[key].insert(j);
            }
        }
        int mx = -1;
        for(auto m_itr = tmap.begin(); m_itr != tmap.end(); m_itr++){
            mx = std::max(mx, (int)m_itr->second.size());
            auto tset = m_itr->second;
            cout<<m_itr->first<<" -\n";
            for_each(tset.begin(), tset.end(), [](auto index){
                    cout<<index<<endl;
                    });
            
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
