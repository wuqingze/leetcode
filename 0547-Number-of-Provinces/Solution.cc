class UF{
public:
    vector<int> root;
    vector<int> rank;
    UF(int n){
        root = vector<int>(n);
        for(int i=0;i<n;i++) root[i]=i;
        rank = vector<int>(n, 1);
    }
    
    int find(int i){
        if(i == root[i]) return i;
        root[i] = find(root[i]);
        return root[i];
    }
    
    void merge(int i, int j){
        int iroot = find(i);
        int jroot = find(j);
        if(rank[iroot]<=rank[jroot]){
            root[iroot] = jroot;
        }else{
            root[jroot] = iroot;
        }
        if(rank[iroot] == rank[jroot]){
            rank[jroot] += 1;
        }
    }
    
    int countgroup(){
        unordered_set<int> count;
        int n = root.size();
        for(int i=0;i<n;i++){
            count.insert(find(i));
        }
        return count.size();
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    uf.merge(i, j);
                }
            }
        }
        return uf.countgroup();
    }
};
