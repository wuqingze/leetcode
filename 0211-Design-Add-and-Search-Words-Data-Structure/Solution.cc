#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node{
    bool isEnd;
    vector<Node*> characters;
    Node(){
        isEnd = false;
        characters = vector<Node*>(26, NULL);
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(const string& word){
        int n = word.length();
        auto node = root;
        for(int i=0;i<n;i++){
            int c = word[i]-'a';
            if(not node->characters[c]){
                node->characters[c] = new Node();
            }
            node = node->characters[c];
            if(i== n-1) node->isEnd = true;
        }
    }

    bool search(const string& word, const Node* node, int i, int n){
        if(not node) return false;
        if(i == n-1){
            if('.' == word[i]){
                for(int j=0;j<26;j++)
                    if(node->characters[j] and node->characters[j]->isEnd) return true;
                return false;
            }else{
                if(node->characters[word[i]-'a'] and node->characters[word[i]-'a']->isEnd)
                    return true;
                else return false;
            }
        }
        if('.' == word[i]){
            for(int j=0;j<26;j++)
                if(search(word, node->characters[j], i+1, n)) return true;
            return false;
        }else{
            if(node->characters[word[i]-'a']) return search(word, node->characters[word[i]-'a'], i+1, n);
            else return false;
        }
    }

    bool search(const string& word){
        return search(word, root, 0, word.length());
    }
};

class WordDictionary {
public:
    Trie dict;
    WordDictionary() {
    }
    
    void addWord(string word) {
       dict.insert(word);
    }
    
    bool search(string word) {
        return dict.search(word);
    }
};

int main(){
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout<< wordDictionary.search("pad")<<endl; // return False
    cout<< wordDictionary.search("bad")<<endl; // return True
    cout<< wordDictionary.search(".ad")<<endl; // return True
    cout<< wordDictionary.search("b..")<<endl; // return True
    return 0;
}
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
