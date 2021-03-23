#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n  = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        int ret = 0;
        for(int i=0;i<n;i++){
            ret += std::max(left[i], right[i]);
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    vector<int> ratings(argc-1);
    for(int i=1;i<argc;i++){
        ratings[i-1] = atoi(argv[i]);
    }
    auto ret = s.candy(ratings);
    cout<<ret<<endl;
    return 0;
}

