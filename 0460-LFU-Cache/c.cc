#include <iostream>
#include <map>

using namespace std;
class T{
    public:
    T(){
        cout<<"null constructor"<<endl;
    }

    T(int i){
        cout<<"argument constructor"<<endl;
    }
};

int main(){
    map<int, int> hmap;
    hmap.insert({1,1});
    hmap.insert({2,2});
    hmap.insert({3,3});
    auto node = hmap.find(2);
    node++;
    cout<<node->second<<endl;
    auto t = hmap.find(4);
    if(t==hmap.end()){
        cout<<"find"<<endl;
    }else{
        cout<<"not find"<<endl;
    }
    return 0;
}
