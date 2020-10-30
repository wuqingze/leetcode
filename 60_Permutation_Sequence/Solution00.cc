
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

        static string getPermutation(int n, int k){
            vector<int> nums;
            for(int i=1;i<=n;i++) nums.push_back(i);

            int i=1;
            while(i<k){
                nextPermutation(nums);
                i++;
            }
            string ret;
            for(int c:nums) ret+= '0'+c;
            return ret;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        int n, k;
        is>>n, is>>k;
        string ret = Solution::getPermutation(n, k);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
