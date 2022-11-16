#include <stdio.h>
#include <iostream>

using namespace std;

class Solution{
    public:
        int numberOfRings(string& rings){
            int n = rings.size();
            int* rods = new int[10];
            for(int i=0;i<10;i++) rods[i] = 0;
            for(int i=0,j=1;j<n;i+=2,j+=2){
                if(rings[i] == 'R'){
                    rods[rings[j]-'0'] |= 1;
                }else if(rings[i] == 'G'){
                    rods[rings[j]-'0'] |= 2;
                }else {
                    rods[rings[j]-'0'] |= 4;
                }
            }
            int ret = 0;
            for(int i=0;i<10;i++) if(rods[i] == 7) ret +=1;
            delete rods;
            return ret;
        }
};

int main(){
    Solution solution;
    string rings = "B0B6G0R6R0R6G9";
    auto ret = solution.numberOfRings(rings);
    cout<<ret<<endl;
    return 0;
}
