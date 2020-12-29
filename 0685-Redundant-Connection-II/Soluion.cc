#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
          vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
              int n = edges.size();
              bool isdouble = false;
              vector<int> p1(n+1, -1);
              vector<int> p2(n+1, -1);
              int index = -1;

              for(int i=0;i<n;i++){
                  auto edge = edges[i];
                  if(p1[edge[1]] == -1){
                      p1[edge[1]] = edge[0];
                      p2[edge[1]] = edge[0];
                  }else{
                      p2[edge[1]] = edge[0];
                      isdouble = true;
                      index = edge[1];
                      break;
                  }
              }

              if(isdouble){
                  vector<int> parent(n+1, -1);
                  vector<int> depth(n+1, 0);
                  for(auto edge:edges){
                      if(!(edge[0] == p2[index] && edge[1] == index)){
                          if(!unionRoot(parent, depth, edge[0], edge[1])) return {p1[index], index};
                      }
                  }
                  return {p2[index], index}; 
              }
              else{
                  vector<int> parent(n+1, -1);
                  vector<int> depth(n+1, 0);
                  for(auto edge:edges){
                      if(!unionRoot(parent, depth, edge[0], edge[1])) return edge;
                  }
              }
              return {};
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

            if(depth[iroot] <depth[jroot]) parent[iroot] = jroot;
            else if(depth[jroot] < depth[iroot]) parent[jroot] = iroot;
            else { parent[iroot] = jroot; depth[jroot] += 1;}
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
