#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
          vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
              int n = edges.size();
              vector<int> parent(n+1, -1);
              vector<int> depth(n+1, 0);
              vector<int> p1(n+1, -1);
              vector<int> p2(n+1, -1);
              int dindex = -1;
              vector<int> looppair;
              bool isdoubleparent = false;

              for(int i=0;i<n;i++){
                  auto edge = edges[i];
                  if(p1[edge[1]] == -1){
                      p1[edge[1]] = edge[0];
                      p2[edge[1]] = edge[0];
                  }else{
                      isdoubleparent = true;
                      dindex = edge[1];
                      p2[edge[1]] = edge[0];
                  }
                  if(looppair.empty() && !unionRoot(parent, depth, edge[0], edge[1])) 
                      looppair = edge;
              }

              if(isdoubleparent){
                  auto parent_ = parent[looppair[0]] == -1?looppair[0]:parent[looppair[0]];
                  auto parent1 = parent[p1[dindex]] == -1?p1[dindex]:parent[p1[dindex]];
                  auto parent2 = parent[p2[dindex]] == -1?p2[dindex]:parent[p2[dindex]];
                  if(parent_ == parent1 && parent_ == parent2) return {p2[dindex], dindex};
                  if(parent_ == parent1) return {p1[dindex], dindex};
                  else return {p2[dindex], dindex};
              }
              else return looppair;
          }
    private:
        int findRoot(vector<int> parent, int index){
            while(parent[index] != -1) index = parent[index];
            return index;
        }

        bool unionRoot(vector<int> &parent, vector<int> &depth, int i, int j){
            auto iroot = findRoot(parent, i);
            auto jroot = findRoot(parent, j);
            if(iroot == jroot) return false;

            if(depth[iroot] <depth[jroot]) parent[i] = jroot;
            else if(depth[jroot] < depth[iroot]) parent[j] = iroot;
            else { parent[i] = jroot; depth[jroot] += 1;}
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
        auto result = slt.findRedundantDirectedConnection(edges); 
        cout<<line<<endl;
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    return 0;
}
