#include <iostream>
#include <vector>
#include <sstream>

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
            if(i == n-1){
                node->isEnd = true;
            }
        }
    }

    bool search(const string& word, int pos, int chr){
        int n = word.length();
        auto node = root;
        for(int i=0;i<pos;i++){
            int c = word[i]-'a';
            if(not node->characters[c]){
                return false;
            }else{
                node = node->characters[c];
            }
        }
        for(int i=0;i<26;i++){
            if(i != chr and node->characters[i]){
                auto ptr = node->characters[i];
                if(pos == n-1 and ptr->isEnd) return true;
                for(int j=pos+1;j<n;j++){
                    int c = word[j]-'a';
                    if(not ptr->characters[c]){
                        break;
                    } else ptr = ptr->characters[c];
                    if(j==n-1 and ptr->isEnd) 
                        return true;
                }
            }
        }
        return false;
    }
};


class MagicDictionary {
public:
    Trie trie;
    MagicDictionary() {
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word: dictionary){
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.length();
        for(int i=0;i<n;i++){
            if(trie.search(searchWord, i, searchWord[i]-'a'))
                return true;
        }
        return false;
    }
};

int main(){
	MagicDictionary magicDictionary;
    //magicDictionary.buildDict({"hello", "leetcode", "ab"});;;;;;;
    magicDictionary.buildDict({"a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"});;;;;;;
//    cout<<magicDictionary.search("hello")<<endl; // return False
//    cout<<magicDictionary.search("hhllo")<<endl; // We can change the second 'h' to 'e' to match "hello" so we return True
//    cout<<magicDictionary.search("hell")<<endl; // return False
//    cout<<magicDictionary.search("leetcoded")<<endl; // return False
//    cout<<magicDictionary.search("ab")<<endl; // return False
    cout<<magicDictionary.search("ba")<<endl; // return False
    return 0;
}
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
