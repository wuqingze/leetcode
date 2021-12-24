#include <iostream>
#include <vector>

using namespace std;;
struct E{
    int v;
    string p;
    E(int v_){
        v = v_;
        p = "";
    }
    E(string p_){
        p = p_;
        v = 0;
    }
};

class Solution {
public:
    int cal(vector<E> &l){
        int n = l.size();
        if(n==1) return l[0].v;
        int ret = l[0].v;
        int i=1;
        while(i<n){
            if(l[i].p == "-"){
                ret -= l[i+1].v;
            }else{
                ret += l[i+1].v;
            }
            i += 2;
        }
        return ret;
    }

    int calculate(string s) {
        int n = s.length();
        int i=0;
        vector<E> l;
        while(i<n and s[i] == ' ') i++;
        while(i<n){
            int j = i;
            if(s[j] == '+'){
                l.push_back(E("+"));
                while(++j<n and s[j] == ' ');
            }else if(s[j] == '-'){
                l.push_back(E("-"));
                while(++j<n and s[j] == ' ');
            }else if(s[j] == '*'){
                l.push_back(E("*"));
                while(++j<n and s[j] == ' ');
            }else if(s[j] == '/'){
                l.push_back(E("/"));
                while(++j<n and s[j] == ' ');
            }else{
                while(j<n and s[j]>='0' and s[j]<='9') j++;
                string v = s.substr(i, j-i);
                if(l.size() == 0) l.push_back(E(atoi(v.c_str())));
                else{
                    if(l.back().p == "*"){
                        auto op = l.back();
                        l.pop_back();
                        auto n1 = l.back();
                        l.pop_back();
                        int t = n1.v*atoi(v.c_str());
                        l.push_back(E(t));
                    }else if (l.back().p == "/"){
                        auto op = l.back();
                        l.pop_back();
                        auto n1 = l.back();
                        l.pop_back();
                        int t = n1.v/atoi(v.c_str());
                        l.push_back(E(t));
                    }else{
                        l.push_back(E(atoi(v.c_str())));
                    }
                }
                while(j<n and s[j] == ' ') j++;
            }
            i = j;
        }
        return cal(l);
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution solution;
    cout<<solution.calculate(string(argv[1]))<<endl;;
    return 0;
}
