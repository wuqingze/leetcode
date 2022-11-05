#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    void update(vector<int>& heap, int v, int n){
        heap[0] = v;
        int i = 0;
        int l;
        int r;
        int t;
        while(true){
            l = 2*i+1;
            r = 2*i+2;
            t = i;
            if(l<n and heap[l] < heap[t]) t = l;
            if(r<n and heap[r] < heap[t]) t = r;
            if(i == t) break;
            else{
                swap(heap[i], heap[t]);
                i = t;
            }
        }
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<int> heap(k, 0);
        map<string,int> wordcnt;
        int n = words.size();
        map<int, vector<string>> wmap;
        for(auto word:words){
            wordcnt[word] = wordcnt.count(word)?wordcnt[word]+1:1;
        }
        for(auto itr=wordcnt.begin();itr!=wordcnt.end();itr++){
            wmap[itr->second].push_back(itr->first);
        }
        for(auto itr=wordcnt.begin();itr!=wordcnt.end();itr++){
            if(itr->second>=heap[0]) 
                update(heap, itr->second, k);
        }
        vector<string> ret;
        while(k>0){
            for(auto word:wmap[heap[0]])
                ret.push_back(word);
            update(heap, heap[k-1], --k);
        }
        sort(ret.begin(), ret.end());
        return ret; 
    }
};

int main(){
    Solution solution;
    //vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    int k = 4;
    auto ret = solution.topKFrequent(words, k);
    for(auto word:ret) cout<<word<<endl;
    return 0;
}
