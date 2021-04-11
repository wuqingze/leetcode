#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    string word;
    map<string, int> cnt;
    while(cin>>word){
        if(cnt.find(word) == cnt.end()){
            cnt[word] = 1;
        }else{
            cnt[word] += 1;
        }
    }
    vector<pair<string, int>> l;
    for(auto entry=cnt.begin();entry!=cnt.end();entry++){
        l.push_back({entry->first, entry->second});
    }
    sort(l.begin(), l.end(), [](auto o1, auto o2){
            return o1.second>o2.second;
            });
    for(auto item:l){
        cout<<item.first<<" "<<item.second<<endl;
    }
    return 0;
}
