#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto t:nums) s.insert(t);
        int res = 0;
        int cnt;
        auto i = s.begin();
        while(i != s.end()){
            auto j = i;
            j++;
            cnt = 1;
            while(j!= s.end() and (*i)+1 == *j){
                i++;
                j++;
                cnt += 1;
            }
            res = max(res, cnt);
            i = j;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {3,2,1};
    auto res = solution.longestConsecutive(nums);
    cout<<res;
    return 0;
}
