#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution{
    public:
          static vector<int> findSubstring(string s, vector<string>& words) {
              vector<int> ret;
              unordered_map<string, int> wmap;
              int wlen = words[0].size();
              int slen = s.size();
              if(slen<wlen*words.size()) return {};

              for(auto s:words) wmap[s] = wmap.count(s)?wmap[s]+1:1; 
              int i=0,j=words.size()*wlen-1;
              while(j<slen){
                  unordered_map<string, int> tmap;
                  int ti = 0;
                  while(ti<words.size()){
                      string ts = s.substr(i+ti*wlen, wlen);
                      tmap[ts] = tmap.count(ts)?tmap[ts]+1:1;
                      ti ++;
                  }
                  auto o = wmap.begin();
                  bool isMatched = true;
                  while(o!=wmap.end()){
                      if(!tmap.count(o->first) || tmap[o->first]<wmap[o->first]){
                          isMatched = false;
                          break;
                      }
                      o++;
                  }
                  if(isMatched){
                      ret.push_back(i);
                  }
                  i++;
                  j++;
              }
              return ret;
          }
};

int main(){
    string line;
    while(getline(cin, line)){
        istringstream is(line);
        string s;
        is>>s;
        vector<string> words;
        string t;
        while(is>>t){
            words.push_back(t);
        }
        auto ret = Solution::findSubstring(s, words);
        cout<<line<<endl;
        for(int i=0;i<ret.size();i++){
            cout<<ret[i]<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}
