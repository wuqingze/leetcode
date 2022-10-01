#include <iostream>
#include <vector>

using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        int n = line.size();
        vector<string> arr = {line.substr(0, line.find(" ")), 
                        line.substr(line.find(" ")+1, n-line.find(" "))};
        cout<<arr[0]<<","<<arr[1]<<endl;
    }
    return 0;
}
