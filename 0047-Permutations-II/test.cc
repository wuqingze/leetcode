#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> l = {1,1,1,2,3};
    unordered_map<int, int> tmap;
    for(int c:l) tmap[c]+=1;
    auto ptr = tmap.begin();
    while(ptr != tmap.end()){
        cout<<ptr->first<<" "<<ptr->second<<endl;
        ptr ++;
    }
    return 0;
}
