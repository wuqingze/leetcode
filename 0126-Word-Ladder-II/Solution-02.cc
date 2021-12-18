#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

struct Vertice{
    string value;
    vector<Vertice*> edges;
    Vertice(string str){
        value = str;
    }
    void add(Vertice* v){
        edges.push_back(v);
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, Vertice*> mapdict;
        mapdict[beginWord] = new Vertice(beginWord);
        for(auto word: wordList){
            mapdict[word] = new Vertice(word);
        }
        int n = beginWord.length();
        for(auto ptr=mapdict.begin(); ptr!= mapdict.end();ptr++){
            auto list = nearWords(ptr->first, n);
            for(auto word:list){
                if(mapdict.count(word) != 0){
                    mapdict[ptr->first]->edges.push_back(mapdict[word]);
                }
            }
        }
        auto beginv = mapdict[beginWord];
        auto endv = mapdict[endWord];
        set<Vertice*> pre;
        pre.insert(beginv);
        set<Vertice*> dp;
        dp.insert(beginv);
//        for(auto ptr=mapdict.begin();ptr!=mapdict.end();ptr++){
//            cout<<ptr->second->value<<","<<ptr->second<<endl;
//            for(auto node:ptr->second->edges){
//                cout<<"edge,"<<node<<endl;
//            }
//            cout<<"--------"<<endl;
//        }
        auto l = f(pre, endv, dp);
        if(l.size() == 0) return {};
        vector<vector<string>> result;
        for(auto ll:l){
            vector<string> temp;
            int n = ll.size();
            for(int i=n-1;i>=0;i--){
                temp.push_back(ll[i]->value);
            }
            result.push_back(temp);
        }
        return result;
    }

    vector<string> nearWords(string word, int n){
        vector<string> result;
        for(int i=0;i<n;i++){
            char c = word[i];
            for(int j=0;j<26;j++){
                string nw = word;
                if(c != 'a'+j){
                    nw[i] = 'a'+j;
                    result.push_back(nw);
                }
            }
        }
        return result;
    }

    vector<vector<Vertice*>> f(set<Vertice*> &pre, Vertice* end, set<Vertice*> &dp){
        set<Vertice*> next;
        for(auto node: pre){
            for(auto v: node->edges){
                if(dp.count(v) > 0) continue;
                dp.insert(v);
                next.insert(v);
                if(v == end){
                    vector<vector<Vertice*>> result;
                    for(auto tv:end->edges){
                        if(pre.count(tv) == 1) 
                            result.push_back({end, tv});
                    }
                    return result;
                }
            }
        }

        if(next.size() == 0) return {};
        auto tail = f(next, end, dp);
        if(tail.size() == 0) return tail;

        vector<vector<Vertice*>> result;
        for(auto list: tail){
            auto node = list.back();
            for(auto near:node->edges){
                if(pre.count(near) == 1){
                    auto temp = vector<Vertice*>(list.begin(), list.end());
                    temp.push_back(near);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};

int main(){
//    Vertice* v = new Vertice("h");
//    cout<<v<<endl;
//    set<Vertice*> xxx;
//    xxx.insert(v);
//    for(auto node=xxx.begin();node!=xxx.end();node++)
//        cout<<*node<<endl;
//    cout<<xxx.count(v)<<endl;
//    return 0;
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
