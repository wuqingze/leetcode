class CustomStack {
public:
    int mx;
    vector<int> stck;
    CustomStack(int maxSize) {
        mx = maxSize;
        
    }
    
    void push(int x) {
        if(stck.size() == mx) return;
        stck.push_back(x);
    }
    
    int pop() {
        if(stck.size()==0) return -1;
        int ret = stck.back();
        stck.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        int n = stck.size();
        for(int i=0;i<n and i<k;i++){
            stck[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
