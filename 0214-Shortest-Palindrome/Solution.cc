#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> computePrefix(string& pattern){
        int n = pattern.length();
        if(n==0) return {};
        vector<int> ret(n);
        int k=-1;
        int q = 1;
        ret[0] = -1;
        while(q<n){
            while(k>=0 and pattern[q] != pattern[k+1]){
                k = ret[k];
            }
            if(pattern[q] == pattern[k+1]){
                k = k+1;
            }
            ret[q] = k;
            q += 1;
        }
        return ret;
    }

    string palindrome(string s){
        string ret = s;
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            std::swap(ret[i], ret[j]);
            i += 1;
            j -= 1;
        }
        return ret;
    }

    string shortestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";
        string ts = s+"#"+palindrome(s);
        vector<int> prefix = computePrefix(ts);
        int index = prefix.back();
        return palindrome(s.substr(index+1))+s;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;;
    string s= string(argv[1]);
    Solution solution;
    cout<<solution.shortestPalindrome(s)<<endl;
    return 0;
}
