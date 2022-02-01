#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n,1);
        vector<int> cnt(n,1);
        int mx = 0;
        int ret = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(len[j]+1 == len[i]) cnt[i] += cnt[j];
                    if(len[j]+1 > len[i]){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(mx == len[i]) ret += cnt[i];
            if(mx < len[i]){
                mx = len[i];
                ret = cnt[i];
            }
        }
        return ret;
    }
};
int main(int argc, char* argv[]){
    if(argc<2) return 0;
    vector<int> nums(argc-1);
    for(int i=0;i<nums.size();i++){
        nums[i] = atoi(argv[i+1]);
    }
    Solution solution;
    auto ret = solution.findNumberOfLIS(nums);
    cout<<ret<<endl;
    return 0;
}
