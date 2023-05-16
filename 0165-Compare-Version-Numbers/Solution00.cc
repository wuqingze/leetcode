#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1);
        stringstream v2(version2);
        char delimiter;
        int n1, n2;
        while(v1.good() and v2.good()){
            v1>>n1>>delimiter;
            v2>>n2>>delimiter;
            if(n1<n2) return -1;
            if(n1>n2) return 1;
        }
        while(v1.good()){
            v1>>n1>>delimiter;
            if(n1>0) return 1;
        }
        while(v2.good()){
            v2>>n2>>delimiter;
            if(n2>0) return -1;
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
