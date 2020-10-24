#include <iostream>
#include <vector>

using namespace std;

void test(vector<int> &l){
    l[0] = 1024;
}

int main(){
    vector<int> l(10, 1);
    for(int i=0;i<l.size();i++) cout<<l[i]<<" ";
    cout<<endl;
    test(l);
    for(int i=0;i<l.size();i++) cout<<l[i]<<" ";
    return 0;
}
