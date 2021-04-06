#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> addOperators(string num, int target) {
       vector<string> ret;
       int n = num.size();
       f(num, target, ret, 0, n, "", 0, 0);
       return ret;
    }

    long pow(int n){
        long ret = 1;
        while(n-->0){
            ret *= 10;
        }
        return ret;
    }

    int val(const string& num, int i, int j){
        long ret = 0;
        int c = 0;
        while(i<=j){
            ret += (num[j]-'0')*pow(c);
            j-=1;
            c += 1;
        }
        if(ret >0x7fffffff) return -1;
        return ret;
    }

    void f(const string &num, int target, vector<string> &ret, int pos, int n,
            string expression, long value, long pre){
        if(pos == n){
            if(value == target){
                ret.push_back(expression);
            }
            return;
        }

        for(int i=pos;i<n;i++){
            if(i!=pos and num[pos] == '0') break;
            int cur = val(num, pos, i);
            if(cur == -1) return;
            if(pos == 0){
                f(num, target, ret, i+1, n, expression+to_string(cur), cur, cur);
            }else{
                f(num, target, ret, i+1, n, expression+"+"+to_string(cur), value+cur, cur);
                f(num, target, ret, i+1, n, expression+"-"+to_string(cur), value-cur, -cur);
                f(num, target, ret, i+1, n, expression+"*"+to_string(cur), (value-pre)+pre*cur, pre*cur);
            }
        }
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    string num(argv[1]);
    int target = atoi(argv[2]);
    auto ret = solution.addOperators(num, target);
    for(auto s:ret)
        cout<<s<<endl;
    return 0;
}
