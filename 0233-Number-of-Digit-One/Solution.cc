class Solution {
public:
    int f(string s){
        int ret = 0;
        for(char c:s){
            if(c == '1') ret+=1;
        }
        return ret;
    }
    int countDigitOne(int n) {
        int ret = 0;
        for(int i=1;i<=n;i++){
            ret += f(to_string(i));
        }
        return ret;
    }
};
