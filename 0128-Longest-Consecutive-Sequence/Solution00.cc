#include <iostream>
#include <vector>
#include <map>

using namespace std;

class UF{
public:
    vector<int> parent;
    vector<int> rank;

    UF(int n){
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }

    int find(int i){
        if(i == parent[i]) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }

    void merge(int i, int j){
        int ip = find(i);
        int jp = find(j);

        if(rank[ip] <= rank[jp]){
            parent[ip] = jp;
        }else{
            parent[jp] = ip;
        }

        if(rank[ip] == rank[jp]){
            rank[jp] += 1;
        }
    }

    int maxUnion(){
        int mx=0;
        int n = parent.size();
        vector<int> count(n, 0);
        for(int i=0;i<n;i++){
            count[find(i)] +=1;
            mx = max(mx, count[find(i)]);
        }
        return mx;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        UF uf(n);
        map<int, int> tmap;
        for(int i=0;i<n;i++){
            if(tmap.find(nums[i]) != tmap.end()){
                continue;
            }
            tmap.insert({nums[i], i});
            if(tmap.find(nums[i] -1) != tmap.end()){
                uf.merge(i, tmap[nums[i]-1]);
            }
            if(tmap.find(nums[i] +1) != tmap.end()){
                uf.merge(i, tmap[nums[i]+1]);
            }
        }
        return uf.maxUnion();
    }
};

int main(){
    Solution solution;
    vector<int> nums = {100,4,200,1,3,2};
    auto res = solution.longestConsecutive(nums);
    cout<<res;
    return 0;
}
