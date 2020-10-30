#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
    public:
        static void f(int i, int n, vector<int> &nums, vector<vector<int>> &ret){
            if(i==n){
                vector<int> t(nums);
                ret.push_back(t);
            }

            for(int j=i;j<n;j++){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                f(i+1, n, nums, ret);
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }

        static vector<vector<int>> permute(vector<int> nums){
            vector<vector<int>> ret;
            f(0, nums.size(), nums, ret);
            return ret;
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
        auto ret = Solution::permute(nums);
        cout<<line<<endl;
        cout<<"----------------"<<endl;
        for(auto l:ret){
            for(auto n:l) cout<<n<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}
