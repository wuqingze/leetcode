#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
        static int lengthOfLongestSubstring(string s){
            unordered_map<char, int> window;
            int count = 0;
            for(int i=0,j=0;j<s.size();j++){
                if(window.count(s[j])){
                    i = i>window[s[j]]?i:window[s[j]];
                }
                count = count>j-i+1?count:j-i+1;
                window[s[j]] = j+1;
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
