#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(){
    multiset<string> s;
    s.insert("3");;
    s.insert("2");;
    s.insert("1");;
    for(auto itr=s.begin();itr!=s.end();itr++){
        cout<<*itr<<endl;
    }
    cout<<"----------------"<<endl;
    map<int,int> m;
    m.insert({4,4});
    m.insert({3,3});
    m.insert({2,2});
    m.insert({1,1});
    for(auto itr=m.begin();itr!=m.end();itr++){
        cout<<itr->first<<endl;
    }
    return 0;
}
