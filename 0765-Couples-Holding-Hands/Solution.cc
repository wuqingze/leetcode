#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> indexs(n, -1);
        for(int i=0;i<n;i++){
            indexs[row[i]] = i;
        }
        int res = 0;
        int i=0;
        while(i<n){
            if(row[i] %2==0){
                if(row[i+1] != row[i]+1){
                    int j = indexs[row[i]+1];
                    indexs[row[i+1]] = j;
                    std::swap(row[i+1], row[j]);
                    res += 1;
                }
            }else{
                if(row[i+1] != row[i]-1){
                    int j = indexs[row[i]-1];
                    indexs[row[i+1]] = j;
                    std::swap(row[i+1], row[j]);
                    res += 1;
                }
            }
            i += 2;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> row = {0,2,4,6,7,1,3,5};
    auto res = solution.minSwapsCouples(row);
    cout<<res<<endl;
    return 0;
}
