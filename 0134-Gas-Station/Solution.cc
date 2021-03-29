#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int sum(const vector<int> &l){
        int ret = 0;
        for(int i=0;i<l.size();i++)
            ret += l[i];

        return ret;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if( sum(gas) < sum(cost)){
            return -1;
        }

        int n = gas.size();
        int pre = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(cnt < n){
            auto ownedOil = gas[j] + pre;
            if(ownedOil < cost[j]){
                pre = 0;
                i = j+1<n?j+1:0;
                j = i;
                cnt = 0;
            }else{
                pre = ownedOil - cost[j];
                j = j+1<n?j+1:0;
                cnt += 1;
            }
        }
        return i;
    }
};

int main(){
    string gasline;
    string costline;
    getline(cin, gasline);
    getline(cin, costline);
    istringstream is(gasline);
    int t;
    vector<int> gas;
    while(is>>t){
        gas.push_back(t);
    }
    is = istringstream(costline);
    vector<int> cost;
    while(is>>t){
        cost.push_back(t);
    }
    Solution s;
    auto ret = s.canCompleteCircuit(gas, cost);
    cout<<ret<<endl;
    return 0;
}
