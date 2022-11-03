#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(i<n and nums[i] != 0) i+=1;
        while(j<n and nums[j] == 0) j+=1;
        while(i<n and j<n){
            if(j<=i){
                j += 1;
                while(j<n and nums[j] == 0) j+=1;
            }else{
                swap(nums[i],nums[j]);
                i += 1;
                j += 1;
                while(i<n and nums[i] != 0) i+=1;
                while(j<n and nums[j] == 0) j+=1;
            }
        }
    }
};

int main(){
    Solution solution;
    //vector<int> nums = {0,1,0,3,12};
    vector<int> nums = {0};
    solution.moveZeroes(nums);
    for(auto i:nums) cout<<i<<",";
    cout<<endl;
    return 0;
}
