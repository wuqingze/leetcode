#include <iostream> 
#include <sstream>
#include <vector> 
#include <set> 
#include <algorithm> 

using namespace std;

class Solution{

    public:
        static vector<vector<int>> threeSum(vector<int>& nums){
            if(nums.empty() || nums.size()<3)
                return {};
            sort(nums.begin(), nums.end());

            vector<vector<int>> result;
            for(int i=0;i<nums.size();i++){
                int target = -nums[i];
                int pre = i+1;
                int pst = nums.size()-1;
                while(pre<pst){
                    if(nums[pre]+nums[pst]<target){
                        pre += 1;
                    }else if(nums[pre]+nums[pst]>target){
                        pst -= 1;
                    }else{
                        vector<int> tumple = {nums[i], nums[pre], nums[pst]};
                        result.push_back(tumple);
                        while(pre<pst && nums[pre] == tumple[1])
                            pre += 1;
                        while(pst>pre && nums[pst] == tumple[2])
                            pst -= 1;
                    }
                }
                while(i+1<nums.size() && nums[i+1] == nums[i]) i+=1 ;
            }
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream str(line);
        int num;
        vector<int> nums;
        while(str>>num){
            nums.push_back(num);
        }
        vector<vector<int>> result = Solution::threeSum(nums);
        for(auto tumple:result){
            for(auto n: tumple){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
