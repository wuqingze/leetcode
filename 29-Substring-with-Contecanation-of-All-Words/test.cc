#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

    map<string, int> m;
    m.insert({"hello", 1});
    m.insert({"hello1", 3});
    m.insert({"hello2", 2});
    auto o = m.begin();
    vector<string> l = {"hello", "hello1"};
    while(o != m.end()){
        cout<<o->first<<" "<<o->second<<endl;
        o++;
    }
    for(string s:l){
        if(m.count(s)){
            cout<<"find..."<<s<<endl;
            m[s] = m[s]+1;
        }else{
            m[s] = 1;
        }
        m.insert({s, m.count(s)?m[s]+1:1});
    }
    o = m.begin();
    while(o != m.end()){
        cout<<o->first<<" "<<o->second<<endl;
        o++;
    }
    return 0;
}

