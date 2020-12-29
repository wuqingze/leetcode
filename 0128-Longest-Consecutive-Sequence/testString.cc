#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> list(){
    return vector<int>(10, rand());
}

int main(){
    vector<int> l = {1,2,3,4,5};
    for(auto i:l) cout<<i<<" ";
    cout<<endl;

    unordered_map<string, string> capitals = {
        {"USA", "Washington"},
        {"CN", "Beijing"},
        {"UK", "London"}
    };

    for(auto ptr=capitals.begin(); ptr != capitals.end(); ptr++) 
        cout<<ptr->first<<":"<<ptr->second<<endl;

    for(auto c:list()) cout<<c<<" ";
    cout<<endl;

    cout<<list().size()<<endl;

    string str1 = "hello world";
    if(str1.find("ºÃÈË") != string::npos) cout<<"cotained"<<endl;
    else cout<<"not contianed"<<endl;
    return 0;
}
