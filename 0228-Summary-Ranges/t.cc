#include <iostream>

#include <set>
#include <map>

using namespace std;

void f(map<int, int> &m){
    for(auto itr=m.begin();itr!=m.end();itr++){
        cout<<itr->first<<"->"<<itr->second<<endl;
    }
}
int main(){
    multiset<string> l;
    l.insert("1")
        ;
    l.insert("1");
    l.insert("1");
    l.insert("2");
    l.erase(l.find("1"));
    l.erase(l.begin());
    l.erase(l.begin());
    l.erase(l.begin());
    for(auto itr=l.begin();itr!=l.end();itr++){
        cout<<*itr<<endl;
    }
    cout<<l.size()<<endl;
    map<int, multiset<int>> g;
    g[1] = {1};
    g[1].insert(1);
    g[1].insert(2);
    auto tt = g[1];
    tt.erase(tt.begin());
    cout<<"-------------------------"<<endl;
    for(auto itr=tt.begin();itr != tt.end(); itr++){
        cout<<*itr<<endl;
    }
    cout<<"-------------------------"<<endl;
    for(auto itr=g[1].begin();itr != g[1].end(); itr++){
        cout<<*itr<<endl;
    }
    map<int, int> t1;
    t1[1] = 1;
    t1[2] = 2;
    t1[3] = 3;
    t1[4] = 4;
    for(auto itr=t1.begin(); itr!=t1.end();itr++){
        cout<<"===================="<<endl;
        t1.erase(itr);
        f(t1);
    }
    return 0;
}

