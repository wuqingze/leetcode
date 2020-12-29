#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution{

    public:
        static vector<vector<int>> fourSum(vector<int>& nums, int target){
            if(nums.empty() || nums.size()<4)
                return {};

            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            for(int i=0;i<nums.size(); i++){
                for(int j=i+1;j<nums.size(); j++){
                    int ttarget = target-nums[i]-nums[j];
                    int left = j+1;
                    int right = nums.size()-1;
                    while(left < right){
                        if(nums[left] + nums[right] < ttarget){
                            left += 1;
                        }
                        else if(nums[left] + nums[right] > ttarget){
                            right -= 1;
                        }
                        else{
                            vector<int> tumple = {nums[left], nums[right]};
                            result.push_back({nums[i], nums[j], tumple[0], tumple[1]});
                            while(left < right && nums[left] == tumple[0]) left +=1;
                            while(right > left && nums[right] == tumple[1]) right -= 1;
                        }
                    }
                    while(j < nums.size()-1 && nums[j] == nums[j+1]) j++;
                }
                while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream str(line);

        int target;
        str>>target;

        int num;
        vector<int> nums;
        while(str>> num){
            nums.push_back(num);
        }
        vector<vector<int>> result = Solution::fourSum(nums, target);
        for(auto t : result){
            for(auto n : t){
                cout<< n<< " ";
            }
            cout<<endl;
        }

    }
    return 0;
}
