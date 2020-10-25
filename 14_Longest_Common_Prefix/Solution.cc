#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
    public:
        static string longestCommonPrefix(vector<string> &strs){
            int n = strs.size();
            if(n==0) return "";

            string ret="";
            for(int i=0;i<strs[0].size();i++){
                char c = strs[0][i];
                for(int j=0;j<n;j++)
                    if(i>= strs[j].size() || c != strs[j][i]) return ret;
                ret += c;
            }
            return ret;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        string str;
        vector<string> strs;
        while(is>>str){
            strs.push_back(str);
        }
        string ret = Solution::longestCommonPrefix(strs);
        cout<<line<<endl;;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
