#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    enum OPERATION{
        NONE,
        PLUS,
        MINUS,
        MULT,
        DIVIDE
    };
    
    OPERATION opt(string& val){
        if(val == "+") return OPERATION::PLUS;
        if(val == "-") return OPERATION::MINUS;
        if(val == "*") return OPERATION::MULT;
        if(val == "/") return OPERATION::DIVIDE;
        return OPERATION::NONE;
    }
    
    int evalRPN(vector<string>& tokens) {
       stack<int> stck;
       int n = tokens.size();
        for(int i=0;i<n;i++){
            auto operation = opt(tokens[i]);
            if(operation == OPERATION::NONE){
                stck.push(atoi(tokens[i].c_str()));
            }else if(operation == OPERATION::PLUS){
                int b = stck.top();
                stck.pop();
                int a = stck.top();
                stck.pop();
                stck.push(a+b);
            }else if(operation == OPERATION::MINUS){
                int b = stck.top();
                stck.pop();
                int a = stck.top();
                stck.pop();
                stck.push(a-b);
            }else if(operation == OPERATION::MULT){
                int b = stck.top();
                stck.pop();
                int a = stck.top();
                stck.pop();
                stck.push(a*b);
            }else if(operation == OPERATION::DIVIDE){
                int b = stck.top();
                stck.pop();
                int a = stck.top();
                stck.pop();
                stck.push(a/b);
            }
        }
        return stck.top();
    }
};

int main(){
    string t;
    vector<string> tokens;
    while(cin>>t){
        tokens.push_back(t);
    }
    Solution s;
    auto ret = s.evalRPN(tokens);
    cout<<ret<<endl;
    return 0;
}
