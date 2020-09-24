#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

class Solution{
    public:
        static int threeSumClosest(vector<int>& nums, int target){
            if(nums.empty() ||  nums.size()<3) return INT_MAX;
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            int diff = INT_MAX;
            for(int i=0;i<nums.size() && diff != 0;i+=1){
                int left = i+1;
                int right = nums.size()-1;
                while(left < right){
                    int total = nums[i] + nums[left] + nums[right];
                    if(abs(target - total)<abs(diff))
                        diff = target - total;
                    if(total<target)
                        while(left < right && nums[left] == nums[++left]);
                    else
                        while(left < right && nums[right] == nums[--right]); 
                }
            }
            return target - diff;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream str(line);
        int target;
        str>>target;
        vector<int> nums;
        int num;
        while(str>>num)
            nums.push_back(num);
        int result = Solution::threeSumClosest(nums, target);
        cout<<result<<endl;
    }
    return 0;
}
