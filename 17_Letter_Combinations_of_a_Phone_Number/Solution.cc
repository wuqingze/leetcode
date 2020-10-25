#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        unordered_map<char, vector<char>> table = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
        };

        void recursion(vector<char> arr, int i, int n, string &digits, vector<string> &ret){
            if(i==n){ 
                ret.push_back(string(arr.begin(), arr.end())); 
                return;
            }
            for(auto c: table[digits[i]]){
                arr[i] = c;
                recursion(arr, i+1, n, digits, ret);
            }
        }

        vector<string> letterCombinations(string digits){
            vector<string> ret;
            int n = digits.size();
            vector<char> arr(n,'\0');
            recursion(arr, 0, n, digits, ret);
            return ret;
        }
};

int main(){
    string line;
    Solution solution;
    while(getline(cin, line)){
        auto ret = solution.letterCombinations(line);
        cout<<line<<endl;
        for_each(ret.begin(), ret.end(), [](string s){cout<<s<<endl;});
        cout<<"========================"<<endl;
    }
    return 0;
}

