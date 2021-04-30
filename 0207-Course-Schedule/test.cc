#include <set>
#include <iostream>

using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.erase(0);
    bool t = s.find(1) == s.end();
    cout<<t;
    return  0;
}
