#include <iostream>
#include <vector>

using namespace std;

void f(){
    std::vector<int> l;
    l.push_back(1);
}

int main(){ 
    int a = 0x7fffffff;
    cout<<a<<endl;
    a+= 1;
    cout<<a<<endl;
    int b = 0x80000000;
    cout<<b<<endl;
    int c = 0xffffffff;
    cout<<c<<endl;
    cout<<2*c<<endl;;;
    int d = 0x80000000;
    cout<<d<<endl;
    cout<<d/2<<endl;
    if(-2147483647 >= (d/2)){
        cout<<"yes"<<endl;
    }else cout<<"no"<<endl;
    return 0;}
