#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    int shortest = 0x7fffffff;
    void f(vector<string> &l, set<string> &history, vector<vector<string>> &ret, 
            map<string, vector<string>> &group, int n, string &endWord, int depth){
        if(shortest<depth) return;
        auto word = l.back();
        auto temp(word);
        for(int i=0;i<n;i++){
            char t = temp[i];
            temp[i] = '*';
            auto tl = group[temp];
            for(auto item:tl){
                if(item == endWord){
                    l.push_back(endWord);
                    if(shortest == depth){
                        ret.push_back(vector<string>(l));
                    }else{
                        ret.clear();
                        shortest = depth;
                        ret.push_back(vector<string>(l));
                    }
                    l.pop_back();
                    return;
                }else if(item != word and history.find(item) == history.end()){
                    l.push_back(item);
                    history.insert(item);
                    f(l, history, ret, group, n, endWord, depth + 1);
                    l.pop_back();
                    history.erase(item);
                }
            }
            temp[i] = t;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        int n = beginWord.size();
        vector<string> l;
        l.push_back(beginWord);
        set<string> history;
        history.insert(beginWord);
        map<string, vector<string>> group;
        for(int i=0;i<wordList.size();i++){
            auto key = wordList[i];
            for(int j=0;j<n;j++){
                char t = key[j];
                key[j] = '*';
                if(group.find(key) == group.end()){
                    group.insert({key, {wordList[i]}});
                }else{
                    group[key].push_back(wordList[i]);
                }
                key[j] = t;
            }
        }
        auto it = group.begin();
        for(;it!=group.end();it++)
            cout<<it->first<<endl;
        f(l, history, ret, group, n, endWord, 1);
        return ret;
    }
};

int main(){
    string line;
    Solution s;
    while(getline(cin, line)){
        istringstream is(line);
        string beginWord, endWord;
        vector<string> wordList;
        string t;
        is>>beginWord;
        is>>endWord;
        while(is>>t) wordList.push_back(string(t));
        auto ret = s.findLadders(beginWord, endWord, wordList);
        for(auto &l:ret){
            for(auto &word:l){
                cout<<word<<" ";
            }
            cout<<endl;
        }
        cout<<"--------------------\n";
    }
    return 0;
}
