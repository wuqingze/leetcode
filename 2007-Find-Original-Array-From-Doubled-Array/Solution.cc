#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 == 1 or n == 0) return {};
        vector<int> res;
        multiset<int> tset;
        for(int i:changed) tset.insert(i);
        while(tset.size() >0){
            auto mn = *tset.begin();
            if(*tset.begin() == 0){
                int cnt = tset.count(0);
                if(cnt %2 == 1) return {};
                else{
                    while(cnt-->0){
                        tset.erase(tset.begin());
                    }
                    for(;cnt>0;cnt -= 2) res.push_back(0);
                }
            }else{
                if(tset.count(mn*2)){
                    res.push_back(mn);
                    tset.erase(tset.begin());
                    tset.erase(tset.find(2*mn));
                }else{
                    return {};
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> changed = {1,3,4,2,6,8};
    Solution solution;
    auto ret = solution.findOriginalArray(changed);
    for(int i:ret) cout<<i<<",";
    cout<<endl;
    return 0;
}
