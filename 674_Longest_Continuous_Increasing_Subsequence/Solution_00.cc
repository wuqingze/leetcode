#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution{
    public:
        static int findLengthOfLCIS(vector<int> &nums){
            if(nums.empty()) return 0;
            int count = 1;
            int index = 1;
            int n = nums.size();
            int ans = 1;
            while(index<n){
                if(nums[index] > nums[index-1]){
                    count += 1;
                }else{
                    ans = ans>count?ans:count;
                    count = 1;
                }
                index += 1;
            }
            ans = ans>count?ans:count;
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
