#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
    public:
        static int findMin(vector<int> &nums){
            int n = nums.size();
            if(n==0) return -1;
            if(n == 1) return nums[0];

            int left = 0, right=n-1;
            while(left<right){
                int mid = left + (right-left)/2;
                if(nums[mid] > nums[right]) left = mid+1;
                else if(nums[mid] < nums[right]) right=mid;
                else right = right-1;
            }
            return nums[left];
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        int n;
        istringstream is(line);
        vector<int> nums;
        while(is>>n) nums.push_back(n);
        auto ret = Solution::findMin(nums);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
