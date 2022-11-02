#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void f(int m, int n, vector<vector<char>>& board, int i, int j){
        if(i<0 or i>=m or j<0 or j>=n) return;
        if(board[i][j] == 'X') return;
        if(board[i][j] == '-') return;
        board[i][j] = '-';
        f(m, n, board, i-1, j);
        f(m, n, board, i+1, j);
        f(m, n, board, i, j-1);
        f(m, n, board, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++) f(m,n, board, i, 0);
        for(int i=0;i<m;i++) f(m, n, board, n-1, i);
        for(int i=0;i<n;i++) f(m, n, board, 0, i);
        for(int i=0;i<n;i++) f(m, n, board, m-1, i);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '-') board[i][j] = 'O';
            }
        }
	}
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'x'));
    char t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>t;
            board[i][j] = t;
        }
    }
    s.solve(board);
    for(auto &l:board){
        for(auto &c:l){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}
