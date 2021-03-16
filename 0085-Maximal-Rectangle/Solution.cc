#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int maximalRectangle(vector<vector<char>> &matrix){
            int m = matrix.size();
            if(m ==0) return 0;
            int n = matrix[0].size();
            if(n ==0) return 0;

            vector<int> left(n,0), right(n,n), height(n,0);
            int mx=0;
            for(int i=0;i<m;i++){
                int cur_left =0, cur_right = n-1;
                for(int j=0;j<n;j++){
                    if(matrix[i][j] =='0'){
                        height[j] = 0;
                    }else{
                        height[j] += 1;
                    }
                }

                for(int j=0;j<n;j++){
                    if(matrix[i][j] == '0'){
                        cur_left = j+1;
                        left[j] = 0;
                    }else{
                        left[j] = std::max(left[j], cur_left);
                    }
                }
                for(int j=n-1;j>=0;j--){
                    if(matrix[i][j] == '0'){
                        cur_right = j-1;
                        right[j] = n;
                    }else{
                        right[j] = std::min(right[j], cur_right);
                    }
                }
                for(int j=0;j<n;j++){
                    mx = std::max(mx, (right[j]-left[j]+1)*height[j]);
                }
            }
			return mx;
        }
};

int main(int argc, char* argv[]){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    vector<vector<char>> matrix(m, vector<char>(n, '0'));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }

    for(auto &l:matrix){
        for(auto &c:l){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    Solution s;
    auto ret = s.maximalRectangle(matrix);
    cout<<ret<<endl;
    return 0;
}
