#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> history;
        map<string, set<string>> group;
        int n = beginWord.size();
        for(int i=0;i<wordList.size();i++){
            auto key(wordList[i]);
            for(int j=0;j<n;j++){
                char t = key[j];
                key[j] = '*';
                group[key].insert(wordList[i]);
                key[j] = t;
            }
        }
        vector<string> hl;
        hl.push_back(beginWord);
        history.insert(beginWord);
        int depth = 1;
        while(not hl.empty()){
            vector<string> next;
            for(auto &word:hl){
                auto key(word);
                for(int i=0;i<n;i++){
                    char t = key[i];
                    key[i] = '*';
                    auto relective = group[key];
                    for(auto &tword:relective){
                        if(tword == endWord){
                            return depth +1;
                        }else if(tword != word and history.find(tword) == history.end()){
                            next.push_back(tword);
                            history.insert(tword);
                        }
                    }
                    key[i] = t;
                }
            }
            hl = next;
            depth += 1;
        }
        return 0;
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
        is>>beginWord>>endWord;
        while(is>>t) wordList.push_back(string(t));
        int ret = s.ladderLength(beginWord, endWord, wordList);
        cout<<ret<<endl;
    }
    return 0;
}
