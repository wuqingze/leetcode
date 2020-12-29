#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
    public:
        static void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            if(n <= 1) return;

            int i=n-2;
            int j=n-1;
            while(i>=0 && nums[i]>=nums[i+1]) i-=1;
            if(i>=0){
                while(nums[j]<=nums[i]) j-=1;
                if(i<j){
                    int t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
                }
            }

            i=i+1, j=n-1;
            while(i<=j){
                int t= nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i+=1;
                j-=1;
            }
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int n;
        vector<int> nums;
        while(is>>n){
            nums.push_back(n);
        }
        Solution::nextPermutation(nums);
        cout<<line<<endl;
        for(int n:nums) cout<<n<<" ";
        cout<<endl<<endl;
    }
    return 0;
}
