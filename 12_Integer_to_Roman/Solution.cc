#include <iostream>

using namespace std;

struct Roman{
    string symbol;
    int value;
};

class Solution{
    public:
        Roman table[13] = {
            {"I", 1},{"IV", 4},{"V", 5},{"IX", 9},{"X", 10},
            {"XL", 40},{"L", 50},{"XC", 90},{"C",100},
            {"CD", 400},{"D", 500},{"CM",900},{"M",1000}
        };
        int len = 13;
        string intToRoman(int num){
            string ret = "";
            while(num){
                int i = len-1;
                while(i>0 && table[i].value>num) i--;
                int c = num/table[i].value;
                while(c-->0) ret+= table[i].symbol;
                num = num%table[i].value;
            }
            return ret;
        }
};

int main(){
    int num;
    Solution solution;
    while(cin>>num){
        string ret = solution.intToRoman(num);
        cout<<num<<" "<<ret<<endl;
    }
    return 0;
}
