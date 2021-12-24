#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
enum ATTR{
    LEFT, RIGHT, PLUS, MINUS, NUM
};

struct Node{
    int iv;
    ATTR attr;
    Node(string v, ATTR attr_){
        if(attr_ == ATTR::NUM){
            iv = atoi(v.c_str());
            attr = attr_;
        }else{
            attr = attr_;
        }
    }
};

class Solution {
public:
    int cal(vector<Node> l){
        if(l[0].attr == ATTR::MINUS){
            l[1].iv = 0-l[1].iv;
            l.erase(l.begin());
        }
        while(l.size() >1){
            auto n1 = l[0];
            l.erase(l.begin());
            auto op = l[0];
            l.erase(l.begin());
            auto n2 = l[0];
            l.erase(l.begin());
            int t;
            if(op.attr == ATTR::MINUS){
                t = n1.iv - n2.iv;
            }else{
                t = n1.iv + n2.iv;
            }
            l.insert(l.begin(), Node(to_string(t), ATTR::NUM));
        }
        return l[0].iv;
    }

    int calculate(string s) {
        int ret = 0;
        int n = s.length();
        int i=0;
        vector<Node> l;
        while(i<n and s[i] == ' ') i++;
        int j=i;
        while(i<n){
            int j=i;
            if(s[j] == '('){
                l.push_back(Node("", ATTR::LEFT));
                while(++j<n and s[j] ==' ');
            }else if(s[j] == ')'){
                vector<Node> expression;
                while(l.back().attr != ATTR::LEFT){
                    expression.push_back(l.back());
                    l.pop_back();
                }
                l.pop_back();
                reverse(expression.begin(), expression.end());
                int t  = cal(expression);
                l.push_back(Node(to_string(t), ATTR::NUM));
                while(++j<n and s[j] ==' ');
            }else if(s[j] == '-'){
                l.push_back(Node("", ATTR::MINUS));
                while(++j<n and s[j] ==' ');
            }else if(s[j] == '+'){
                l.push_back(Node("", ATTR::PLUS));
                while(++j<n and s[j] ==' ');
            }else{
                while(j<n and s[j]>='0' and s[j]<='9') j++;
                l.push_back(Node(s.substr(i, j-i), ATTR::NUM));
                while(s[j] == ' ') j++;
            }
            i = j;
        }
        return cal(l);
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    string expression = string(argv[1]);
    Solution solution;
    cout<<solution.calculate(expression)<<endl;
    return 0;
}
