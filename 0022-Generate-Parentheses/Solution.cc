#include <iostream>
#include <vector>

using namespace std;

class Solution{

    public:

        static void f(int i, int j, int n, string s, vector<string> &ret){
            if(s.size() == 2*n){
                ret.push_back(s);
                return;
            }
            if(i<n) f(i+1, j, n, s+'(', ret);
            if(j<i) f(i, j+1, n, s+')', ret);
        }

        static vector<string> generateParenthesis(int n){
            vector<string> ret;
            f(0, 0, n, "", ret);
            return ret;
        }

};

int main(){
    int n;
    while(cin>>n){
        auto ret = Solution::generateParenthesis(n);
        for(auto s:ret){
            cout<<s<<endl;
        }
        cout<<"======================="<<endl;
    }
    return 0;
}
