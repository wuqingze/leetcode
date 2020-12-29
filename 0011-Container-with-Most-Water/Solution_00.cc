#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    public:
        static int maxArea(vector<int> &height){
            int mx = 0;
            for(int i=0;i<height.size()-1;i++)
                for(int j=i+1;j<height.size();j++){
                    int container = (height[i]<height[j]?height[i]:height[j])*(j-i);
                    mx = mx>container?mx:container;
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

