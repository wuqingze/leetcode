#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

int c = 0;
class Solution{

    public:
        static bool isParenthesis(vector<char> &arr, int n){
            vector<char> stack;
            for(int i=0;i<n;i++){
                char c = arr[i];
                if(c=='('){
                    stack.push_back(c);
                }else{
                    if(!stack.empty() && stack.back()=='('){
                        stack.pop_back();
                    }else{
                        stack.push_back(c);
                    }
                }
            }
            return stack.empty();
        }

        static void swap(vector<char> &arr, int i, int j){
            char c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }

        static void f(int i, int n, vector<char> &arr, vector<string> &ret, unordered_set<string> &tset){
            if(i==n){
                c+=1;
                cout<<c<<endl;
                if(isParenthesis(arr, n)) {
                    string s(arr.begin(), arr.end());
                    if(!tset.count(s)){
                        tset.insert(s);
                        ret.push_back(s);
                    }
                }
                return;
            }

            for(int j=i;j<n;j++){
                swap(arr, i, j);
                f(i+1, n, arr, ret, tset);
                swap(arr, i, j);
            }
        }

        static vector<string> generateParenthesis(int n){
            vector<char> arr(2*n, '(');
            for(int i=n;i<2*n;i++) arr[i]=')';
            vector<string> ret;
            unordered_set<string> tset;
            f(0, 2*n, arr,ret, tset); 
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
