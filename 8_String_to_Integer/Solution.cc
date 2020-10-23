#include <iostream>
#include <cmath>
#include <limits.h>
#include <sstream>

using namespace std;

class Solution{
    public:
        static int myAtoi(string s){
            char nums[200];
            bool isNegative = false;
            int i =0;
            int n = s.size();
            if(n==0) return 0;
            for(;i<n;i++) if(s[i] != ' ') break;
            if(i==n) return 0;
            if(s[i] == '+'){ i+=1; isNegative=false;}
            else if(s[i]>='0' && s[i]<='9'){ isNegative=false;}
            else if(s[i] == '-'){ i+= 1; isNegative=true;}
            else return 0;

            int c=0;
            for(;i<n;i++){ 
                if(s[i]>='0' && s[i]<='9') nums[c++] = s[i];
                else break;
            }
            i =  0;
            for(;i<c;i++) if(nums[i] != '0') break;
            if(c==0 || i==c) return 0;
            for(int j=i;j<c;j++) nums[j-i] = nums[j];
            c = c-i;

            if(c>=11) return isNegative?INT_MIN:INT_MAX;
            int ret = 0;
            for(int i=c-1;i>=0;i--){
                long t = (nums[i]-'0')*pow(10, c-1-i);
                if(t>INT_MAX) return isNegative?INT_MIN:INT_MAX;
                int temp = int(t);
                if(INT_MAX-ret<temp) return isNegative?INT_MIN:INT_MAX;
                ret += temp;
            }
            return isNegative?0-ret:ret;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        int ret = Solution::myAtoi(line);
        cout<<line<<endl;
        cout<<ret<<endl;
        cout<<"--------------"<<endl;
    }
    return 0;
}
