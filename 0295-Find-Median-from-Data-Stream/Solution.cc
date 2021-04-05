class MedianFinder {
public:
    priority_queue<long> small;
    priority_queue<long, vector<long>, greater<long>> large;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size() == large.size()){
            large.push(num);
            if(large.size() == 1) return;
            if(large.top()<small.top()){
                long lt = large.top();
                long st = small.top();
                large.pop();
                small.pop();
                large.push(st);
                small.push(lt);
            }
        }else{
            small.push(num);
            if(large.top()<small.top()){
                long lt = large.top();
                long st = small.top();
                large.pop();
                small.pop();
                large.push(st);
                small.push(lt);
            }
        }
    }
    
    double findMedian() {
        if(small.size() == large.size()){
            double t = (double)small.top() + (double)large.top();
            return t/2;
        }else{
            return large.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
