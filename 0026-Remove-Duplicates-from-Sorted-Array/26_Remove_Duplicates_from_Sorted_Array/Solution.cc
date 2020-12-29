#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
    public:
        static int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if(n==0) return 0;
            int c=0;
            for(int i=0;i<n;i++) if(nums[c] != nums[i]) nums[++c] = nums[i];
            return c+1;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        vector<int> nums;
        int n;
        while(is>>n)nums.push_back(n);
        cout<<line<<endl;
        int len = Solution::removeDuplicates(nums);
        for(int i=0;i<len;i++) cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}
