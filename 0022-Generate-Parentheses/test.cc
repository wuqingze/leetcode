#include <iostream>
#include <stdlib.h>

using namespace std;
int main(){
//    vector<char> arr = {'a', 'b', 'c'};
//    char arr[3] = {'a', 'b', 'c'};
//    string s(arr.cbegin(), arr.cend());
    char *arr = (char*) malloc(10);
    *(arr+1) = 'c';
    string s(arr);
    cout<<s<<endl;
    return 0;
}
