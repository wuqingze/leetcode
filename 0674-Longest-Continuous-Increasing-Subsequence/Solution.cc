#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution{
    public:
        static int findLengthOfLCIS(vector<int> &nums){
            int ans=0, anchor=0;
            for(int i=0; i<nums.size();i++){
                if(i>0 && nums[i-1] >=nums[i]) anchor = i;
                ans = ans>i-anchor+1?ans:i-anchor+1;
            }
            return ans;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        int num;
        vector<int> nums;
        while(args>>num){
            nums.push_back(num);
        }
        for_each(nums.begin(), nums.end(), [](int n){cout<<n<<" ";});
        cout<<endl;
        int ans = Solution::findLengthOfLCIS(nums);
        cout<<"length of LCTIS:"<<ans<<endl;
    }
    return 0;
}
