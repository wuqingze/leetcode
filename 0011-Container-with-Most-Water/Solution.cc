#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    public:
        static int maxArea(vector<int> &height){
            int i=0, j=height.size()-1;
            int mx = 0;
            while(i<j){
                int mn = (height[i]<height[j]?height[i]:height[j])*(j-i);
                mx = mx>mn?mx:mn;
                if(height[i]<height[j]) i+=1;
                else j-=1;
            }
            return mx;
        }
};

int main(){
    int n;
    vector<int> height;
    while(cin>>n){
        height.push_back(n);
    }
    int ret = Solution::maxArea(height);
    for_each(height.begin(), height.end(), [](int n){cout<<n<<" ";});
    cout<<ret<<endl;
    cout<<endl;
    return 0;
}

