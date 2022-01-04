#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node{
    bool started;
    vector<Node*> next;
    Node(){
        started = false;
        next = vector<Node*>(26,NULL);
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        root = new Node();
    }

    void add(string& word){
        int n = word.length();
        if(n == 0){
            root->started = true;
            return;
        }
        auto node = root;
        for(int i=n-1;i>=0;i--){
            int c = word[i]-'a';
            if(not node->next[c]){
                node->next[c] = new Node();
            }
            node = node->next[c];
            if(i==0){
                node->started = true;
            }
        }
    }

    bool palindromed(const string& s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i] != s[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }

    void f(string& word,int wi,  Node* node, string pre, vector<vector<int>> &ret, map<string, int> &index){
        if(node->started){
            if(palindromed(pre)){
                string t = string(pre);
                reverse(t.begin(), t.end());
                t += word;
                reverse(t.begin()+pre.length(), t.end());
                int j = index[t];
                if(j != wi) ret.push_back({wi, j});
            }
        }

        for(int i=0;i<26;i++){
            if(node->next[i]){
                f(word, wi, node->next[i], pre+string(1,('a'+i)), ret, index);
            }
        }
    }

    void search(string& word, int wi, vector<vector<int>> &ret, map<string, int> &index){
        int n = word.length();
        auto node = root;
        if(root->started and word != ""){
            if(palindromed(word)){
                ret.push_back({wi, index[""]});
            }
        }
        for(int i=0;i<n;i++){
            int c = word[i] - 'a';
            if(not node->next[c]){
                return;
            }else{
                if(node->next[c]->started and i!=n-1){
                    if(palindromed(word.substr(i+1, n-i-1))){
                        string key = word.substr(0, i+1);
                        reverse(key.begin(), key.end());
                        int j = index[key];
                        ret.push_back({wi, j});
                    }
                }
            }
            node = node->next[c];
        }
        f(word, wi, node, "", ret, index);
    }

};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        if(n<=1) return {};
        Trie trie;
        map<string, int> index;
        for(int i=0;i<n;i++){
            trie.add(words[i]);
            index[words[i]] = i;
        }
        vector<vector<int>> ret;
        for(int i=0;i<n;i++){
            trie.search(words[i], i, ret, index);
        }
        return ret;
    }
};

int main(int argc, char* argv[]){
    if(argc<2) return 0;
    vector<string> words;
    for(int i=1;i<argc; i++){
        words.push_back(string(argv[i]));
    }
    Solution solution;
    auto ret = solution.palindromePairs(words);
    for(auto item:ret){
        cout<<'['<<item[0]<<','<<item[1]<<']'<<",";
    }
    cout<<endl;
    return 0;
}
