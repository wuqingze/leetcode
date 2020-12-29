#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node{
    char val;
    int index;
    Node(char v, int i):val(v), index(i){}
};

class Solution {
public:
    static int longestValidParentheses(string s) {
        vector<Node*> stack;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') stack.push_back(new Node(s[i], i));
            else{
                if(!stack.empty() && stack.back()->val == '('){
                    stack.pop_back();
                }else{
                    stack.push_back(new Node(s[i], i));
                }
            }
        }
        if(stack.empty()) return s.size();
        int mx = 0;
        stack.insert(stack.begin(), new Node('\0', -1));
        stack.push_back(new Node('\0', s.size()));
        int i=0, n=stack.size();
        while(i<n-1){
            int distance = stack[i+1]->index - stack[i]->index-1;
            if(distance > 1){
                mx = distance > mx?distance:mx;
            }
            i++;
        }
        return mx;
    }
};

int main(){
    string line;
    while(getline(cin, line)){
        auto ret = Solution::longestValidParentheses(line);
        cout<<line<<endl;
        cout<<ret<<endl<<endl;
    }
    return 0;
}
