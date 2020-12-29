#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

class Solution{

    public:
        static bool isParenthesis(char *arr, int n){
            vector<char> stack;
            for(int i=0;i<n;i++){
                char c = *(arr+i);
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

        static void swap(char *arr, int i, int j){
            char t=*(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = t;
        }

        static void f(int i, int n, char *arr, vector<string> &ret, unordered_set<string> &tset){
            if(i==n){
                if(isParenthesis(arr, n)) {
                    string s = string(arr);
                    if(!tset.count(s)){
                        tset.insert(s);
                        ret.push_back(string(arr));
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
            char *arr = (char*) malloc(n*2);
            for(int i=0;i<n;i++){
                *(arr+i) = '(';
            }
            for(int i=n;i<2*n;i++) *(arr+i) = ')';
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
