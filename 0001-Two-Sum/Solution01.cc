#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        static vector<int> twoSum(vector<int>& nums, int target){
            int n = nums.size();
            if(n<2) return {};
            vector<pair<int, int>> l;
            for(int i=0;i<n;i++){
                l[i] = {nums[i], i};
            }
            sort(l.begin(), l.end(), [](auto &o1, auto &o2){
                    return o1.first<o2.first;}
                );

            int i=0,j=n-1;
            while(i<j){
                auto o1 = l[i].first;
                auto o2 = l[j].first;
                if(o1+o2 == target){
                    return {l[i].second, l[j].second};
                }else if(o1+o2 < target) i += 1;
                else j -= 1;
            }
            return {};
        }
};

int main(){
    return 0;
}
