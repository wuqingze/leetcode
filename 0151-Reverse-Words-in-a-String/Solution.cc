#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
//    string reverseWords(string s) {
//        int i=0;
//        int n = s.size();
//        while(i<n and s[i] == ' ') i+= 1;
//        int j = i;
//        string ret = "";
//        while(i<n){
//            while(j<n and s[j] != ' ') j+=1;
//            ret = s.substr(i, j-i) +" "+ ret;
//            i = j;
//            while(i<n and s[i] == ' ') i+=1;
//            j = i;
//        }
//        return ret.substr(0, ret.size()-1);
//    }
//
	void reverse_(string& s, int i, int j){
        j -= 1;
        while(i<j){
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i += 1;
            j -= 1;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        int end =0;
        int i = 0;
        while(i<n and s[i] == ' ') i+= 1;
        int j = i;
        while(j<n and s[j] != ' ') j += 1;
        while(i<n){
            reverse_(s, i, j);
            int k = i;
            while(k<j){
                s[end++] = s[k++];
            }
            if(end < n) s[end++] = ' ';
            i = j;
            while(i<n and s[i] == ' ') i+=1;
            j = i;
            while(j<n and s[j] != ' ') j+=1;
        }
        return s[end-1] == ' '?s.substr(0, end-1):s.substr(0, end);
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    string line(argv[1]);
    auto ret = solution.reverseWords(line);
    cout<<ret<<"-"<<endl;
    return 0;
}
