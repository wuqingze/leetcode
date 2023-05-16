#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i_1 = 0,j_1 = 0;
        int i_2 = 0,j_2 = 0; 
        while(j_1<n and j_2<m){
            while(j_1<n and version1[j_1] != '.') j_1+=1;
            while(j_2<m and version2[j_2] != '.') j_2+=1;
            int t1 = stoi(version1.substr(i_1, j_1-i_1).c_str());
            int t2 = stoi(version2.substr(i_2, j_2-i_2).c_str());
            if(t1<t2) return -1;
            else if(t1>t2) return 1;
            j_1 +=1;
            i_1 = j_1;
            j_2 += 1;
            i_2 = j_2;
        }

        if(i_1 >=n and i_2>= m) return 0;
        else if(i_1>=n) return stoi(version2.substr(i_2, j_2-i_2)) == 0? 0:-1; 
        else if(i_2>=m) return stoi(version1.substr(i_1, j_1-i_1)) == 0? 0:1;
        else {
            int t1 = stoi(version1.substr(i_1, j_1-i_1).c_str());
            int t2 = stoi(version2.substr(i_2, j_2-i_2).c_str());
            if(t1<t2) return -1;
            else if(t1>t2) return 1;
        }
        return 0;
    }
};


int main(int argc, char* argv[]){
    if(argc<2) return 0;
    Solution solution;
    string version1(argv[1]);
    string version2(argv[2]);
    printf("%d\n", solution.compareVersion(version1, version2));
    return 0;
}
