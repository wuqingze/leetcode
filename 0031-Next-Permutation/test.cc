#include <iostream>

using namespace std;

void f(int i, int n, string &s){
    if(i>=n-1) { cout<<s<<endl;return;}

    for(int j=i;j<n;j++){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        f(i+1, n, s);
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main(){
    string s = "123";
    f(0, 3, s);
    return 0;
}
