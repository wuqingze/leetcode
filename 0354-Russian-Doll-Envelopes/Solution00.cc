#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {

    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution solution;
    vector<vector<int>> envelopes((argc-1)/2, vector<int>(2));
    for(int i=0;i<(argc-1)/2;i++){
        envelopes[i] = {atoi(argv[i*2+1]), atoi(argv[i*2+2])};
    }
    auto ret = solution.maxEnvelopes(envelopes);
    cout<<ret<<endl;
    return 0;
};
