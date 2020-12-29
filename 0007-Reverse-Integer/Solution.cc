#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;
class Solution{
    public:
        static int reverse(int x){
            if(x==INT_MIN) return 0;

            int nums[32];
            int c =0;
            bool isNegative = x<0;
            x = isNegative?0-x:x;
            int t = x;
            while(t){
                nums[c++] = t%10;
                t/=10;
            }
            int ret = 0;
            for(int i=c-1;i>=0;i--){
                long t = nums[i]*pow(10, c-1-i);
                if(t>INT_MAX) return 0;
                t =nums[i]*pow(10, c-1-i);
                if(INT_MAX-ret<t){
                    if(isNegative && i==0 && INT_MAX-ret-t==-1) return INT_MIN;
                    return 0;
                }else{
                    ret += t;
                }
            }
            return isNegative?0-ret:ret;
        }
};

int main(){
    int x;
    while(cin>>x){
        int ret = Solution::reverse(x);
        cout<<x<<" "<<ret<<endl;
    }
    return 0;
}
