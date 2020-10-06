#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <time.h>
#include <algorithm>
using namespace std;

class Heap{
    private:
        int pos = 0;
        int len;
        vector<int> heap;
        void maxHeap(int i){
            if(i>=len) return;
            int largest = i;
            int l = 2*i + 1;
            int r = 2*(i+1);
            if(l<len && heap[l]>heap[i]) largest = l;
            if(r<len && heap[r]>heap[i]) largest = r;

            int t = heap[largest];
            heap[largest] = heap[i];
            heap[i] = t;
            if(i!= largest) maxHeap(largest);
        };

        int _maxHeap(int i){
            while(i>0){
                int parent = (i-1)/2;
                if(heap[i] > heap[parent]){
                    int t = heap[i];
                    heap[i] = heap[parent];
                    heap[parent] = t;
                }else{
                    return i;
                }
                i = parent;
            }
            return i;
        }

     

    public:
        Heap(int l){
            len = l;
            while(l-->0) heap.push_back(0x80000000);
        };

        void insert(int val){
            heap[pos] = val;
            int index = _maxHeap(pos);
            pos += 1;
        };

        int findIndex(int val){
            for(int i=0;i<len;i++){if(heap[i] == val) return i;}
            return -1;
        }

        int top(){ return heap[0];};
        void remove(int val){
            int index = findIndex(val);
            while(index < len){
                bool isLeaf = index>=len/2;
                if(isLeaf){
                    heap[index] = heap[len-1];
                    _maxHeap(index);
                    pos -= 1;
                    break;
                }else{
                    int largest = 2*index+1;
                    int right = 2*(index+1);
                    if(right<len && heap[right] > heap[largest]) largest = right;
                    heap[index] = heap[largest];
                    index = largest;
                }
            }
        };

        bool check(){
            for(int i=1;i<len;i++){
                int parent = (i-1)/2;
                if(heap[i]>heap[parent]){
                    for_each(heap.begin(), heap.end(), [](int n){cout<<n<<" ";});
                    cout<<endl<<"heap bad: "<<i<<endl;
                    return false;
                }
            }
            return true;
        }
};

class Solution{
    public:
        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            if(nums.empty()) return {};
            Heap heap(k);
            vector<int> result;
            auto tm = time(nullptr);
            for(int i=0;i<k;i++){ 
                heap.insert(nums[i]);
            }
            cout<<"initial insert time "<< time(nullptr)-tm<<endl;
            result.push_back(heap.top());
            int l=0, r=k, n = nums.size();
//            heap.remove(nums[0]);

            while(r<n){
                tm = time(nullptr);
                heap.remove(nums[l]);
                cout<<"remove insert time "<< time(nullptr)-tm<<endl;
                tm = time(nullptr);
                heap.insert(nums[r]);
                cout<<"insert time "<< time(nullptr)-tm<<endl;
                if(!heap.check()){ cout<<"l:"<<l<<",r:"<<r<<",nums[l]:"<<nums[l]<<", nums[r[:"<<nums[r]<<endl; return {};};
                result.push_back(heap.top());
                r++;
                l++;
            }
            return result;
        }

};
int main(){
    string line;
    while(getline(cin, line)){
        istringstream args(line);
        int k;
        vector<int> nums;
        args>>k;
        int num;
        while(args>>num){
            nums.push_back(num);
        }
        auto result = Solution::maxSlidingWindow(nums, k);
        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
