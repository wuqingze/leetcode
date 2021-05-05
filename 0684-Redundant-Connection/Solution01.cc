#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class UF{
public:
}
;
class Solution{
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> nums(n+1, -1), rank(n+1, 0); 
            for(auto edge:edges) 
                if(!unionSet(nums, rank, edge[0], edge[1])) return edge;
            return {};
        }

    private:
        int findRoot(vector<int> &nums, int index){
            while(nums[index] != -1) index = nums[index];
            return index;
        }

        bool unionSet(vector<int> &nums, vector<int> &rank, int i, int j){
            int iroot = findRoot(nums, i);
            int jroot = findRoot(nums, j);
            if(iroot == jroot) return false;
            if(rank[iroot] < rank[jroot]){
                nums[iroot] = jroot;
            }else if(rank[iroot] > rank[jroot]){
                nums[jroot] = iroot;
            }else{
                nums[iroot] = jroot;
                rank[jroot] += 1;
            }
            return true;
        }
};

int main(){
    string line;
    Solution slt;
    while(getline(cin, line)){
        istringstream is(line);
        int num;
        int index = 0;
        vector<vector<int>> edges;
        while(is>>num){
            if(index%2==0){
                edges.push_back(vector<int>(2));
                edges[edges.size()-1][0] = num;
            }else{
                edges[edges.size()-1][1] = num;
            }
            index ++;
        }
        auto result = slt.findRedundantConnection(edges); 
        cout<<line<<endl;
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    return 0;
}
