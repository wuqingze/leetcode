#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge_sort(vector<long>& nums, int i, int j, int &cnt){
        if(i>=j) return;
        if(i == j-1){
            if(2*nums[j]<nums[i]){
                cnt += 1;
            }
            if(nums[i]>nums[j]) {
                swap(nums[i], nums[j]);
            }
            return;
        }

        int mid = i+(j-i)/2;
        merge_sort(nums, i, mid, cnt);
        merge_sort(nums, mid+1, j, cnt);

        vector<long> temp;
        int k1 = i;
        int k2 = mid+1;

        vector<long> doublearr;
        for(int k=mid+1;k<=j;k++){
            doublearr.push_back(nums[k]*2);
        }

        while(k1<=mid and k2<=j){
            if(nums[k1]<=doublearr[k2-(mid+1)]){
                k1+=1;
            }else{
                cnt += (mid-k1+1);
                k2 += 1;
            }
        }

        k1 = i;
        k2 = mid+1;

        while(k1<=mid and k2<=j){
            if(nums[k1]<nums[k2]){
                temp.push_back(nums[k1]);
                k1 += 1;
            }else{
                temp.push_back(nums[k2]);
                k2 += 1;
            }
        }
        while(k1<=mid){
            temp.push_back(nums[k1]);
            k1 += 1;
        }
        while(k2<=j){
            temp.push_back(nums[k2]);
            k2 += 1;
        }

        int k3 = i;
        for(auto c:temp){
            nums[k3] = c;
            k3 += 1;
        }
    }


    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        vector<long> temp;
        for(auto i:nums) temp.push_back(i);
        merge_sort(temp, 0, nums.size()-1, cnt);
        for(int i=0;i<nums.size();i++) nums[i] = temp[i];
        return cnt;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647}; 
  //  vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    //vector<int> nums = {1,3,2,3,1};
    //vector<int> nums = {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
//    vector<int> nums = {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233 };



    vector<long> temp;
    for(auto i:nums) temp.push_back(i);

    int cnt = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(2*temp[j]<temp[i]){
                cout<<temp[i]<<","<<temp[j]<<endl;
                cnt += 1;
            }
        }
    }
    cout<<cnt<<endl;
    int result = s.reversePairs(nums);
//    for(auto i:nums) cout<<i<<",";
//    cout<<endl;
    cout<<result<<endl;
    return 0;
}
