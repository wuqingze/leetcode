#include <iostream>

using namespace std;
class Solution{
    public:
        static bool isPalindrome(int x){
            if(x<0) return false;
            int nums[10];
            int c=0;
            while(x){
                nums[c++] = x%10;
                x/=10;
            }
            int i=0, j=c-1;
            while(i<=j) if(nums[i++] != nums[j--]) return false;
            return true;
        }
};

int main(){
    int x;
    while(cin>>x){
        bool ret = Solution::isPalindrome(x);
        cout<<x<<" "<<ret<<endl;
    }
    return 0;
}
