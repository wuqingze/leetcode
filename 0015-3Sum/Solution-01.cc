#include <iostream> 
#include <sstream>
#include <vector> 
#include <set> 
#include <algorithm> 

using namespace std;

class Solution{

    public:
        static vector<vector<int>> threeSum(vector<int>& nums){
            int n = nums.size();
            if(n<3) return {};
            vector<vector<int>> ret;
            sort(nums.begin(), nums.end());
            int j,k,target, t;
            int i=0;
            while(i<n-2){
                j = i+1;
                k = n-1;
                target = -nums[i];
                while(j<k){
                    t = nums[j] + nums[k];
                    if(t == target){
                        ret.push_back({nums[i], nums[j], nums[k]});
                        while(j<k and nums[j] == nums[++j]);
                        while(j<k and nums[k] == nums[--k]);
                    }else if(t<target){
                        while(j<k and nums[j] == nums[++j]);
                    }else{
                        while(j<k and nums[k] == nums[--k]);
                    }
                }
                while(i<n-2 and nums[i] == nums[++i]);
            }
            return ret;
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
