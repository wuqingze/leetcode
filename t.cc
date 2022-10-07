#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    string s1 = "123";
    string s2 = "456";
    multiset<string> ss;
    ss.insert("1");
    ss.insert("1");
    ss.insert("2");
    ss.erase(ss.begin());

    for(auto itr=ss.begin();itr!=ss.end();itr++){
        cout<<*itr<<endl;
    }
    vector<string> l = {"1","2"};
    cout<<to_string(l)<<endl;
    if(s1<s2){
        cout<<"yes"<<endl;
    }else{

        cout<<"yes"<<endl;
    }
    return 0;
}
