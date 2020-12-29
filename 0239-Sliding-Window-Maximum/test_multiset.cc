#include <set>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    multiset<int> s;
    for(int i=10;i>0;i--){s.insert(rand());}
//    auto iterator = s.begin();
//    while(iterator != s.end()){
//        cout<<*iterator++<<endl;
//    }
    cout<<endl;
    auto iterator = s.rbegin();
    while(iterator != s.rend()){
        cout<<*iterator++<<endl;
    }
    return 0;
}
