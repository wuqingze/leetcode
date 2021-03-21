#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void f(int i, int j, int m, int n, vector<vector<char>> &board){
        if(i>=m) return;
        if(j>=n) return;
        if(i<0) return;
        if(j<0) return;
        if(board[i][j] == 'X') return;
        if(board[i][j] == '-') return;

        board[i][j] = '-';
        f(i-1, j, m, n, board);
        f(i+1, j, m, n, board);
        f(i, j-1, m, n, board);
        f(i, j+1, m, n, board);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m ==0) return;
        int n = board[0].size();
        if(n==0) return;
        for(int i=0;i<n;i++){
            f(0, i, m, n, board);
        }
        for(int i=0;i<n;i++){
            f(m-1, i, m, n, board);
        }
        for(int i=0;i<m;i++){
            f(i, 0, m, n, board);
        }
        for(int i=0;i<m;i++){
            f(i, n-1, m, n, board);
        }
		for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '-'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
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
