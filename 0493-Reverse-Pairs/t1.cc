#include <vector>

using namespace std;

class Solution {
public:
    void index(vector<int> &nums, int i, int j, int key){
        int mid;
        while(i<=j){
            mid = i+(j-i)/2;
            if(nums[mid]>key){
                if(mid == 0) return 0;
                else{
                    if(nums[mid-1]<=key){
                        return mid;
                    }else{
                        j = mid -1;
                    }
                }
            }else{
                i += 1;
            }
        }
        return -1;
    }
    
    void merge_sort(vector<int>& nums, int i, int j, int &cnt){
        if(i>=j) return;
        if(i == j-1){
            if(nums[i]>nums[j])
            {
                swap(nums[i], nums[j]);
                if(nums[i]>2*nums[j]){
                    cnt += 1;
                }
            return;
        }
        
        int mid = i+(j-i)/2;
        merge_sort(nums, i, mid);
        merge_sort(nums, mid+1, j);
        
        vector<int> temp;
        int k1 = i;
        int k2 = mid+1;
        
        while(k1<=mid and k2<=j){
            if(nums[k1]<=nums[k2]){
                temp.push_back(nums[k1]);
                k1 += 1;
            }else{
                if(2*nums[k2]>0){
                    int inx = index(nums, k1, mid);
                    if(inx != -1){
                        cnt += (mid-inx+1);
                    }
                }
                temp.push_back(nums[k2]);
                k2 += 1;
            }
        }
        while(k1<=mid){
            temp.push_back(nums[k1]);
        }
        while(k2<=j){
            temp.push_back(nums[k2]);
        }
    }
    
    
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        merge_sort(nums, 0, nums.size()-1, cnt);
        return cnt;
    }
};

int main(){ return 0;}
