#include <iostream>

using namespace std;

int main(){
    string s = "123";
    int i=0, j=s.size()-1;
    while(i<=j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    cout<<s<<endl;
    return 0;
}
