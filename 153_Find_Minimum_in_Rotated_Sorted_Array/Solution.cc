#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -5001;
        if(n == 1) return nums[0];

        int l=0, r=n-1;
        if(nums[r] > nums[0]) return nums[0];

        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid+1<n && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(mid-1>=0 && nums[mid-1]>nums[mid]) return nums[mid];
            if(nums[mid] > nums[0]) l = mid+1;
            else r = mid -1;
        }
        return -5001;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums;
        istringstream is(line);
        int n;
        while(is>>n){
            nums.push_back(n);
        }
        int ret = Solution::findMin(nums);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
