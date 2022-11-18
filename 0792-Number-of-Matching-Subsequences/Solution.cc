#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool f(string& s, string& word){
        int m = s.size();
        int n = word.size();
        int i=0;
        int j=0;
        while(i<m and j<n){
            if(s[i] == word[j]){
                i +=1 ;
                j += 1;
            }
            else i += 1;
        }
        return j==n;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        for(auto word:words){
            if(f(s, word)){
                ret += 1;
            }
        }
        return ret;
    }
};

int main(){
    vector<int> l(200);
    l['a'] = 1;
    l['b'] = 2;
    for(int i=0;i<200;i++) cout<<l[i]<<",";
    return 0;
}
