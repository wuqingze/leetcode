#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    Node(){
        characters = vector<Node*>(26, NULL);
        isEnd = false;
    }
    vector<Node*> characters;
    bool isEnd;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string word){
        int n = word.length();
        auto node = root;
        for(int i=0;i<n;i++){
            if(not node->characters[word[i] -'a']){
                node->characters[word[i]-'a'] = new Node();
            }
            node = node->characters[word[i]-'a'];
            if(i == n-1){
                node->isEnd = true;
            }
        }
    }

    string prefix(const string &word){
        int n = word.length();
        auto node = root;
        string result = "";
        for(int i=0;i<n;i++){
            if(node->characters[word[i]-'a']){
                result += word[i];
                if(node->characters[word[i]-'a']->isEnd){
                    break;
                }else{
                    node = node->characters[word[i]-'a'];
                }
            } else{
                result = "";
                break;
            }
        }
        return result == "" ? word : result;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        if(0 ==  sentence.length()) return sentence;
        Trie trie;
        for(auto str: dictionary)
            trie.insert(str);
        string result = "";
        stringstream ss;
        ss<<sentence;
        string word;
        while(ss>>word){
            result += trie.prefix(word) + " "; 
        }
        return result.substr(0, result.length()-1);
    }
};


int main(){
    string sentence;
    getline(cin, sentence);
    string t;
    vector<string> dictionary;
    while(cin>>t){
        dictionary.push_back(t);
    }
    Solution s;
    cout<<s.replaceWords(dictionary, sentence)<<endl;
    return 0;
}
