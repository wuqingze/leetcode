#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
struct Node{
    vector<Node*> siblings;
    bool isEnd;
    Node(){
        siblings = vector<Node*>(26, NULL);
        isEnd = false;
    }
};

class Solution {
public:
    void build(string& word, Node* root){
        int n=word.length();
        auto node = root;
        for(int i=0;i<n;i++){
            int c = word[i]-'a';
            if(not node->siblings[c]){
                node->siblings[c] = new Node();
            }
            node = node->siblings[c];
            if(i==n-1) node->isEnd = true;
        }
    }

    void search(vector<vector<char>>& board, int i, int j, int m, int n, vector<vector<bool>>& accessedMatrix,
            Node* node, string word, set<string>& result){
        if(node->isEnd) result.insert(word);
        if(i<0 or i>=m){
            return;
        }
        if(j<0 or j>=n){
            return;
        }
        if(accessedMatrix[i][j]){
            return;
        }
        accessedMatrix[i][j] = true;
        char c = board[i][j];
        if(node->siblings[c-'a']){
            search(board, i-1, j, m, n, accessedMatrix, node->siblings[c-'a'], word+c, result);
            search(board, i+1, j, m, n, accessedMatrix, node->siblings[c-'a'], word+c, result);
            search(board, i, j-1, m, n, accessedMatrix, node->siblings[c-'a'], word+c, result);
            search(board, i, j+1, m, n, accessedMatrix, node->siblings[c-'a'], word+c, result);
        }
        accessedMatrix[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(auto &word:words){
            build(word, root);
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> accessedMatrix = vector<vector<bool>>(m, vector<bool>(n, false));
        set<string> resultSet;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                search(board, i, j, m, n, accessedMatrix, root, "", resultSet);
            }
        }
        vector<string> result;
        for(auto ptr=resultSet.begin();ptr!=resultSet.end();ptr++){
            result.push_back(*ptr);
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    int m, n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    vector<vector<char>> board = vector<vector<char>>(m, vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    vector<string> words;
    string temp;
    while(cin>>temp){
        words.push_back(temp);
    }
    Solution solution;
    auto ret = solution.findWords(board, words);
    for(auto word:ret){
        cout<<word<<" ";
    }
    cout<<endl;
    return 0;
}
