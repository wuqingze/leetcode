#include <iostream>
using namespace std;

class Solution{
    public:
        static int lengthOfLongestSubstring(string s){
            int index[128] = {};
            int n = s.size();
            int ans = 0;
            for(int i=0,j=0; j<n; j++){
                i = i>index[s[j]]?i:index[s[j]];
                ans = ans > j-i+1?ans:j-i+1;
                index[s[j]] =  j+1;
            }
            return ans;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        cout<<line<<" - length of longest substring "<<Solution::lengthOfLongestSubstring(line)<<endl;
    }
    return 0;
}
