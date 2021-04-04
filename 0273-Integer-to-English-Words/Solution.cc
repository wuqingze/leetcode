#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> l1 = {
        "Zero", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine"};
        vector<string> l2 = {"Ten", "Eleven", 
        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "SevenTeen", "Eighteen", "Nineteen"};
    vector<string> l3 = {
        "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"};
    
    vector<string> l4 = {"", "Thousand",
                         "Million", "Billion"
    };
    
    string f(int n){
        if(n<10) return l1[n];
        else if(n<20) return l2[n%10];
        else if(n<100){
            int t = n%10;
            if(t == 0){
                return l3[n/10-2];
            }else{
                return l3[n/10 -2] + " " + l1[t];
            }
        }else{
            int t = n%100;
            if(t == 0){
                return l1[n/100] + " Hundred";
            }else{
                return l1[n/100] + " Hundred "+ f(t);
            }
        }
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string ret = "";
        int cnt = 0;
        while(num != 0){
            int t = num%1000;
            if(t != 0){
                string t1 = f(t);
                if(cnt == 0){
                    ret = t1;
                }else{
                    if(ret.size() == 0){
                        ret = t1 + " " + l4[cnt];
                    }else{
                        ret = t1 + " "+l4[cnt]+" "+ret;
                    }
                }
            }
            cnt += 1;
            num /= 1000;
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    cout<<solution.numberToWords(atoi(argv[1]));
    return 0;
} 
