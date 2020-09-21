#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using std::vector;
using std::cin;
using std::cout;
using std::getline;
using std::unordered_map;
using std::istringstream;
using std::stoi;
using std::string;

class Solution {
    public:
        static vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> tmap;
            for(int i=0;i<nums.size(); i++){
                int diff = target - nums[i];
                if(tmap.count(diff)){
                        return {tmap[diff], i};
                }
                tmap.insert({nums[i], i});
            }
            return {};
        }
};

int main(){

    string line;
    while(getline(cin, line)){
        istringstream argline(line);
        string t;
        argline>>t;
        std::string::size_type sz;   // alias of size_t
        int target = std::stoi (t, &sz);
        vector<int> nums;
        while(argline>>t){
            nums.push_back(std::stoi(t, &sz));
        }
        auto result = Solution::twoSum(nums, target);
        for(auto i : result){
            cout<<i<<" ";
        }
        cout<<std::endl;
    }
    return 0;
}
