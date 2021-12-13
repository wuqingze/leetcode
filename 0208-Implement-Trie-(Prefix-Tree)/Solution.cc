#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Node{
public:
    Node(){
        characters = vector<Node*>(26, NULL);
        isEnd = false;
    }
    vector<Node*> characters;
    bool isEnd;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        auto node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(not node->characters[word[i] - 'a']){
                node->characters[word[i]-'a'] = new Node();
            }
            node = node->characters[word[i]-'a'];
            if(i == n-1){
                node->isEnd = true;
            }
        }
    } 

    bool search(string word) {
        int n = word.length();
        auto node = root;
        for(int i=0;i<n;i++){
            if(not node->characters[word[i]-'a']) return false;
            node = node->characters[word[i]-'a'];
            if(i==n-1 and not node->isEnd) return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        auto node = root;
        for(int i=0;i<n;i++){
            if(not node->characters[prefix[i]-'a']) return false;
            node = node->characters[prefix[i]-'a'];
        }
        return true;
    }
};

int main(){
    Trie tries;
    tries.insert("apple");
    auto node = tries.root;
    cout<<tries.search("apple");
    cout<<tries.startsWith("ap");
    return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
