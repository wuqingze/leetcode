#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution{
    public:
        static int findMax(vector<int>& nums, int i, int j){
            int ans = nums[i];
            for(int k=i;k<=j;k++)
                ans = ans>nums[k]?ans:nums[k];
            return ans;
        }

        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            if(nums.empty()) return {};

            unordered_map<int, int> window;
            int mx = nums[0], l=0, r=0, n= nums.size();
            vector<int> result;
            for(;r<k;r++){
                mx = mx>nums[r]?mx:nums[r];
                window[nums[r]] = window.count(nums[r])?window[nums[r]]+1:1;
            }
            result.push_back(mx);
            window[nums[l]] -= 1;
            int pre = nums[l];
            l +=1;
            while(r<n){
                if( pre == mx && (!window.count(pre) || window[pre] == 0)){
                    mx = findMax(nums, l, r);
                }
                if(nums[r]>=mx){
                    mx = nums[r];
                }
                result.push_back(mx);
                pre = nums[l];
                window[nums[l]] -= 1;
                window[nums[r]] = window.count(nums[r])?window[nums[r]]+1:1;
                r++;
                l++;
            }
            return result;
        }

};
int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        int k;
        vector<int> nums;
        args>>k;
        int num;
        while(args>>num){
            nums.push_back(num);
        }
        auto result = Solution::maxSlidingWindow(nums, k);
        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
