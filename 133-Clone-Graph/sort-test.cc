#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> l = vector<int>(10);
    for(int i=0;i<10;i++) l[i] = rand();
    sort(l.begin(), l.end(), [](int a, int b){ return a>b;});
    for(int i=0;i<10;i++) cout<<l[i]<<" ";
    cout<<endl;;
    sort(l.begin(), l.end());
    for(int i=0;i<10;i++) cout<<l[i]<<" ";
    cout<<endl;;
    return 0;
}
