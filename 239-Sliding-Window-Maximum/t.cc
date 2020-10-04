#include <iostream>
#include <vector>
#include <map>
//#include <multi_map>
using namespace std;

int t(vector<int> a){
//int t(int (&a)[]){
    //if(a.length() == 0) return 0;
    if(a.size() == 0) return 0;

    int i = 0;
    //for(int j=1;j<a.length(); j++){
    for(int j=1;j<a.size(); j++){
        if(a[j] != a[i]){
            i++;
            a[i] = a[j];
        }
    }
    return i+1; 
}

int main(){
    vector<int> a;
    int nums[6] = {1,2,3,4,1,5};
    for(int i=0;i<6;i++){
        a.push_back(nums[i]);
    }
    int l = t(a);
    for(int i=0;i<l;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
    int i = 0x80000000;
    cout<<i<<endl;
    multimap<int, int> tmap;
    tmap.insert({1,1});
    tmap.insert({1,2});
    tmap.insert({1,3});
    tmap.insert({1,4});
    auto item = tmap.find(1);
    while(item != tmap.end()){cout<<item->second<<" "; item++;}
    cout<<endl;
    tmap.erase(tmap.find(1));
    item = tmap.find(1);
    while(item != tmap.end()){cout<<item->second<<" "; item++;}
}
