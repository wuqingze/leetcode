#include <iostream>
#include <vector>

using namespace std;

int f(int n){
    int result = 1;
    while(n){
        if(n%2==1) break;
        result *= 2;
        n /=2;
    }
    return result;
}

vector<int> twoDiff(vector<int> &nums){
    int mark = 0;
    for(auto i:nums) mark ^= i;
    mark = f(mark);
    cout<<"mark:"<<mark<<endl;

    vector<int> result = {0,0};
    for(auto i:nums)
        if(i&mark != 0) result[0] ^= i;
        else result[1] ^= i;
    return result;
}

int main(){
    int n;
    vector<int> nums;
    while(cin>>n) nums.push_back(n);
    for(auto i:nums) cout<<i<<" ";
    cout<<endl;
    for(auto c:twoDiff(nums)) cout<<c<<" ";
    return 0;
}
