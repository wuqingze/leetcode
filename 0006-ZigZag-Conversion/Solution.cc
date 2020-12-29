#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution{
    public:
        static string convert(string s, int numRows) {
            if(numRows<=1) return s;
            vector<string> rows = vector<string>(numRows>s.size()?s.size():numRows);
            bool downGo = false;
            int curRow = 0;
            for(char c:s){
                rows[curRow] += c;
                if(curRow==0 || curRow==numRows-1) downGo = !downGo;
                curRow += downGo?1:-1;
            }
            string result;
            for(string row:rows) result += row;
            return result;
        }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is = istringstream(line);
        string s;
        int numRows;
        is>>s;
        is>>numRows;
        string str = Solution::convert(s, numRows);
        cout<<s<<" "<<numRows<<endl;
        cout<<str<<endl;
        cout<<"-----------"<<endl;
    }
    return 0;
}
