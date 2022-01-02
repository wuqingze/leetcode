#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void f(int i, int j, vector<int> &indexes, vector<int> &nums, vector<int> &count){
        if(i>=j) return;
        if(i == j-1){
            if(nums[indexes[i]] > nums[indexes[j]]){
                count[indexes[i]] += 1;
                swap(indexes[i], indexes[j]);
            }
            return;
        }
        int mid = (j-i)/2 + i;
        f(i, mid, indexes, nums, count);
        f(mid+1, j, indexes, nums, count);
        vector<int> temp;
        int k1 = i;
        int k2 = mid+1;
        while(k1<=mid and k2<=j){
            if(nums[indexes[k1]] > nums[indexes[k2]]){
                temp.push_back(indexes[k2]);
                k2 += 1;
            }else{
                count[indexes[k1]] += (k2-(mid+1));
                temp.push_back(indexes[k1]);
                k1 += 1;
            }
        }
        while(k1<=mid){
            count[indexes[k1]] += (j-mid);
            temp.push_back(indexes[k1]);
            k1 += 1;
        }
        while(k2<=j){
            temp.push_back(indexes[k2]);
            k2 += 1;
        }
        for(int k=i;k<=j;k++){
            indexes[k] = temp[k-i];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexes(n);
        for(int i=0;i<n;i++) indexes[i] = i;
        vector<int> count(n, 0);
        f(0, n-1, indexes, nums, count);
        for(auto i:indexes)
            cout<<nums[i]<<" ";
        cout<<endl;
        return count;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    vector<int> nums;
    for(int i=1;i<argc;i++){
        nums.push_back(atoi(argv[i]));
    }
    Solution solution;
    auto ret = solution.countSmaller(nums);
    for(auto i:ret)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
