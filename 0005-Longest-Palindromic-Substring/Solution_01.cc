#include <iostream>
#include <sstream>
using namespace std;

class Solution{

    public:
        static bool isPld(string s, int i, int j){
            while(i<=j) if(s[i++] != s[j--]) return false;
            return true;
        }

        static string longestPalindrome(string s) {
            string result = "";
            int count = 0;
            for(int i=0;i<s.size();i++){
                for(int j=i;j<s.size();j++){
                    if(isPld(s, i, j)){
                        int l = j-i+1;
                        if(count<l){
                            result = s.substr(i, l);
                            count = l;
                        }
                    }
                }
            }
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        string pldStr = Solution::longestPalindrome(line);
        cout<<line<<endl;
        cout<<pldStr<<endl;;
        cout<<"--------------"<<endl;
    }
    return 0;
}
