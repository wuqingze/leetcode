#include <iostream> 
#include <sstream>
#include <vector> 
#include <set> 
#include <algorithm> 

using namespace std;

class Solution{

    public:
        static vector<vector<int>> threeSum(vector<int>& nums){
            if(nums.empty() || nums.size()<3)
                return {};
            vector<vector<int>> result;
            set<string> unique_set;
            for(int i=0; i<nums.size(); i++){
                for(int j=i+1; j<nums.size(); j++){
                    for(int k=j+1; k<nums.size(); k++){
                        if(nums[i] + nums[j] + nums[k] == 0){
                            vector<int> t = {nums[i], nums[j], nums[k]};
                            sort(t.begin(), t.end(), [](int v1, int v2){return v1<v2;});
                            string ts = to_string(t[0])+","+to_string(t[2])+","+to_string(t[2]);
                            if(!unique_set.count(ts)){
                                unique_set.insert(ts);
                                result.push_back({nums[i], nums[j], nums[k]});
                            }
                        }
                    }
                }
            }
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream str(line);
        int num;
        vector<int> nums;
        while(str>>num){
            nums.push_back(num);
        }
        vector<vector<int>> result = Solution::threeSum(nums);
        for(auto tumple:result){
            for(auto n: tumple){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
