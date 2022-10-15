class StockPrice {
public:
    map<int,int> timeprices;
    multiset<int> prices;
    pair<int,int> currentPrice = {-1,-1};
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        int prvp = -1;
        if(timeprices.find(timestamp) != timeprices.end()){
            prvp = timeprices[timestamp];
        }
        if(prvp != -1) {
            prices.erase(prices.find(prvp));
        }
                    prices.insert(price);

        timeprices[timestamp] = price;
        if(timestamp>=currentPrice.first){
            currentPrice = {timestamp, price};
        }

    }
    
    int current() {
        auto ret = currentPrice.second;
        return ret;
    }
    
    int maximum() {
        auto ret =  *(prices.rbegin());
        return ret;
    }
    
    int minimum() {
        auto ret = *(prices.begin());
        return ret;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
