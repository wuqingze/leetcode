#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int left=0, right = n-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[right]) left = mid+1;
            else right = mid;
        }
        return nums[left];
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
