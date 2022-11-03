#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>&  candles, int target, int direction){
        int n = candles.size();
        int l = 0;
        int h = n-1;
        int mid;
        if(direction <0){
            while(l<=h){
                mid = l+(h-l)/2;
                if(candles[mid] == target) return mid;
                else if(candles[mid] < target){
                    if(mid == n-1) return n-1;
                    if(candles[mid+1] == target) return mid+1;
                    else if(candles[mid+1] < target) l = mid+1;
                    else return mid;
                }else{
                    h = mid-1;
                }
            }
         }else{
            while(l<=h){
                mid = l+(h-l)/2;
                if(candles[mid] == target) return mid;
                else if(candles[mid] > target){
                    if(mid == 0) return 0;
                    if(candles[mid-1] == target) return mid-1;
                    else if(candles[mid-1] > target) h = mid-1;
                    else return mid;
                }else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles;
        vector<int> plates;
        int n = s.size();
        int i=0;
        plates.push_back(0);
        while(i<n){
            if(s[i] == '|') break;
            i += 1;
        }
        if(i<n) candles.push_back(i);
        int j = i+1;
        while(j<n){
            while(j<n and s[j] !='|') j+=1;
            if(j<n){
                plates.push_back(j-i-1+plates.back());
                candles.push_back(j);
                i = j;
                j = i+1;
            }
        }
        vector<int> ret;
        for(auto query: queries){
            if(plates.size() == 1){
                ret.push_back(0);
                continue;
            }
            int l = search(candles, query[0],1);
            int r = search(candles, query[1],-1);
            if(l>=0 and r>=0 and l<r) ret.push_back(plates[r]-plates[l]);
            else ret.push_back(0);
        }
        return ret;
    }
};

int main(){
    Solution solution;
    string s = "**|**|***|";
    vector<vector<int>> queries = {{2,5},{5,9}};
    //string s = "***|**|*****|**||**|*"; 
    //vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};
    auto ret = solution.platesBetweenCandles(s, queries);
    for(auto i:ret) cout<<i<<",";
    cout<<endl;
    return 0;
}
