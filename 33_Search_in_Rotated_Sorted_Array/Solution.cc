#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    static int binarySearch(int i, int j, vector<int> &nums, int target){
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) i = mid+1;
            else j=mid-1;
        }
        return -1;
    }

    static int findMid(vector<int>& nums){
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return 0;

        int left=0, right=n-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) left = mid+1;
            else right = mid;
        }
        return left;
    }

    static int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        int rotated = findMid(nums);
        int ret = binarySearch(0, rotated-1, nums, target);
        return ret==-1?binarySearch(rotated, n-1, nums, target):ret;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int target;
        vector<int> nums;
        is>>target;
        int n;
        while(is>>n) nums.push_back(n);
        auto ret = Solution::search(nums, target);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
