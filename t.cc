#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector<int> l = {1,1,2};
    vector<int> ll = {3,3};
    sort(l.begin(), l.end());
    string s = "4321";
    sort(s.begin(), s.end()); ;
    cout<<s<<endl;
    return 0;
}
