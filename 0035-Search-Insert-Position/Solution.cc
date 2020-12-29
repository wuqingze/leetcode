#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
    public:
        static int searchInsert(vector<int> &nums, int target){
            int left = 0, right=nums.size()-1;
            while(left<right){
                int mid = left+(right-left)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) left = mid+1;
                else right = mid -1;
            }
            return nums[left]<target?left+1:left;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int target;
        int n;
        vector<int> nums;
        is>>target;
        while(is>>n) nums.push_back(n);
        auto ret = Solution::searchInsert(nums, target);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
