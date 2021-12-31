#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool valid(const string &s){
        int n = s.length();
        vector<char> stack;
        bool ret = true;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                stack.push_back('(');
            }else if(s[i] == ')'){
                if(not stack.empty() and stack.back() == '('){
                    stack.pop_back();
                }else{
                    ret = false;
                    break;
                }
            }else{
                continue;
            }
        }
        return ret and stack.size() == 0;
    }

    set<string> f(set<string> &l){
        if(l.size() == 0) return l;

        set<string> ret;
        for(auto ptr=l.begin(); ptr!=l.end();ptr++){
            if(valid(*ptr)){
                ret.insert(*ptr);
            }
        }
        if(not ret.empty()) return ret;
        set<string> pool;
        for(auto ptr=l.begin();ptr!=l.end();ptr++){
            int n=(*ptr).length();
            for(int i=0;i<n;i++){
                if((*ptr)[i] == '(' or (*ptr)[i] == ')')
                pool.insert((*ptr).substr(0,i)+(*ptr).substr(i+1, n));
            }
        }
        return f(pool);
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string> pool;
        pool.insert(s);
        auto temp = f(pool);
        vector<string> ret;
        for(auto ptr=temp.begin();ptr!=temp.end();ptr++){
            ret.push_back(*ptr);
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution solution;
    auto ret = solution.removeInvalidParentheses(string(argv[1]));
    for(auto s:ret)
        cout<<s<<endl;
    return 0;
}
