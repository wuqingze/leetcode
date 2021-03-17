#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
class Solution{
    public:
        int maxProfit(vector<int>& prices){
            int n = prices.size();
            vector<int> first(n,0);
            vector<int> second(n,0);

            int mn = prices[0];
            for(int i=0;i<n;i++){
                first[i] = prices[i]-mn>0?prices[i]-mn:0;
                mn = std::min(mn, prices[i]);
            }
            int mx = prices[n-1];
            for(int i=n-1;i>=0;i--){
                second[i] = mx-prices[i]>0?mx-prices[i]:0;
                mx = std::max(mx, prices[i]);
            }
            mx = first[0];
            for(int i=0;i<n;i++){
                mx = std::max(first[i], mx);
                first[i] = mx;
            }
            mx = second[n-1];
            for(int i=n-1;i>=0;i--){
                mx = std::max(second[i], mx);
                second[i] = mx;
            }
            mx = 0;
            for(int i=0;i<n-1;i++){
                mx = std::max(mx, first[i]+second[i+1]);
            }
            mx = std::max(mx, first[n-1]);
            mx = std::max(mx, second[0]);
            return mx;
        }
};

int main(int argc, char* argv[]){
    string argstr;
    Solution s;
    while(getline(cin,argstr)){
        vector<int> prices;
        int t;
        istringstream is(argstr);
        while(is>>t) prices.push_back(t);
        auto ret = s.maxProfit(prices);
        cout<<ret<<endl;
    }
    return 0;
}
