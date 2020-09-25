#include <iostream>
#include <set>
using namespace std;

class Solution{
    public:
        static int lengthOfLongestSubstring(string s){
            set<char> window;
            int i=0, j=0;
            int n = s.size();
            int count = 0;
            while(i<n && j<n){
                if(!window.count(s[j])){
                    window.insert(s[j++]);
                    count = count>j-i?count:j-i;
                }else{
                    while(i<j && s[i] !=s[j]) window.erase(s[i++]);
                    window.erase(s[i++]);
                }
            }
            return count;
       }
};

int main(){
    string line;
    while(getline(cin, line)){
        cout<<line<<" - length of longest substring "<<Solution::lengthOfLongestSubstring(line)<<endl;
    }
    return 0;
}
