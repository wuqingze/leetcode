#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        static void f(int i, int n, vector<int> &comb, unordered_map<int, int> counter, vector<vector<int>> &ret){
            if(i==n){
                ret.push_back(vector<int>(comb));
                return;
            }

            auto ptr = counter.begin();
            while(ptr != counter.end()){
                int count = ptr->second;
                if(count == 0) {ptr++; continue;};
                ptr->second = count-1;
                comb[i] = ptr->first;
                f(i+1, n, comb, counter, ret);
                ptr->second = count;
                ptr++;
            }
        }

        static vector<vector<int>> permuteUnique(vector<int> &nums){
            unordered_map<int, int> counter;
            vector<vector<int>> ret;
            for(int n:nums) counter[n]+=1; 
            f(0, nums.size(), nums, counter, ret);
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
        auto ret = Solution::permuteUnique(nums);
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
