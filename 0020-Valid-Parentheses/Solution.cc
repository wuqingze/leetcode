class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int n = s.size();
        if(n%2==1) return false;
        for(char c:s){
            switch(c){
                case '(':
                    stack.push_back(c);
                    break;
                case ')':
                    if(stack.empty()) return false;
                    if(stack.back() == '(') stack.pop_back();
                    else stack.push_back(')');
                    break;
                case '{':
                    stack.push_back(c);
                    break;
                case '}':
                    if(stack.empty()) return false;
                    if(stack.back() == '{') stack.pop_back();
                    else stack.push_back('}');                    
                    break;
                case '[':
                    stack.push_back(c);
                    break;
                case ']':
                    if(stack.empty()) return false;
                    if(stack.back() == '[') stack.pop_back();
                    else stack.push_back(']');                    
                    break;
            }
        }
        return stack.empty();
    }
};
