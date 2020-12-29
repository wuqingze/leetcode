#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

class Solution{
    public:
        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            multiset<int> window;
            vector<int> result;
            for(int i=0;i<nums.size();i++){
                window.insert(nums[i]);
                if(i>=k-1){
                    result.push_back(*window.rbegin());
                    auto iterator = window.find(nums[i-k+1]);
                    window.erase(iterator);
                }
            }
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        int k;
        vector<int> nums;
        args>>k;
        int num;
        while(args>>num){
            nums.push_back(num);
        }
        auto result = Solution::maxSlidingWindow(nums, k);
        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
