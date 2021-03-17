#include <iostream>
#include <stack>
#include <vector>
#include <regex>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        auto start = 0U;
        auto end = path.find("/");
        while(end != string::npos){
            auto t = path.substr(start, end-start);
            if(t.size() != 0){
                if(t == ".."){
                    if(not s.empty())s.pop();
                } else s.push(t);
            }
            start = end + 1;
            end = path.find("/", start);
        }
        string ret = "";
        while(!s.empty()){
            auto t = s.top();
            if(t!="."){
                ret = t + "/" + ret;
            }
            s.pop();
        }
        ret = "/" + ret;
        if(ret.size() > 1) ret.erase(ret.size()-1, ret.size());
        return ret;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    cout<<s.simplifyPath(string(argv[1]));
    return 0;
}
