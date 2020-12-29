#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
    public:
        static vector<int> searchRange(vector<int> &nums, int target){
            int n = nums.size();
            if(n==0) return {-1, -1}; 
            vector<int> ret(2, -1);
            int left=0, right=n-1;
            while(left <= right){
                int mid = left+(right-left)/2;
                if(nums[mid] == target){
                    int i=mid, j=mid;
                    while(i>=0 && nums[i] == target) i--;
                    while(j<n && nums[j] == target) j++;
                    ret[0] = i+1;
                    ret[1] = j-1;
                    break;
                }else if(nums[mid]<target){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            return ret;
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
        auto ret = Solution::searchRange(nums, target);
        cout<<line<<endl;
        cout<<ret[0]<<" "<<ret[1]<<endl<<endl;
    }
    return 0;
}
