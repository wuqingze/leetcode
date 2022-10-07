#include <iostream>
#include <vector>


using namespace std;

int main(){
    vector<int> l;
    l.push_back(1);
    l.push_back(1);
    l.pop_back();
    for(auto c:l)cout<<c<<endl;
    return 0;
}
