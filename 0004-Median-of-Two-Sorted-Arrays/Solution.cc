#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>
using namespace std;
class Solution{
    public:
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n=nums1.size(), m=nums2.size();
            int isEven = (n+m)%2==0;
            if(n ==0) return isEven?double(nums2[m/2]+nums2[(m-1)/2])/2:nums2[m/2];
            if(m ==0) return isEven?double(nums1[n/2]+nums1[(n-1)/2])/2:nums1[n/2];

            int l=-1, h=n-1;
            while(l<=h){
                int i = (l+h)/2;
                int j = (n+m)/2-2-i;
                if(j<-1){ h=i-1; continue;}
                if(j>m-1){ l = i+1; continue;}

                int t1 = i==-1?INT_MIN:nums1[i];
                int t2 = j==-1?INT_MIN:nums2[j];
                int t3 = i==n-1?INT_MAX:nums1[i+1];
                int t4 = j==m-1?INT_MAX:nums2[j+1];

                int A = t1>t2?t1:t2;
                int B = t3>t4?t4:t3;

                if(A<=B){
                    if(isEven) return double(A+B)/2;
                    else return double(B);
                }else{
                    if(t1>t2) h=i-1;
                    else  l = i+1;
                }
            }
            return 0.00f;
        }
};

int main(){
    vector<int> nums1;
    vector<int> nums2;
    string line;
    int c = 0;
    while(getline(cin, line)){
        cout<<line<<endl;
        if(line.empty()) continue;
        if(c==0){
            c+=1;
            nums1.clear();
            istringstream args(line);
            int num;
            while(args>>num){
                nums1.push_back(num);
            }
        }else{
            c = 0;
            nums2.clear();
            istringstream args(line);
            int num;
            while(args>>num){
                nums2.push_back(num);
            }
            double result = Solution::findMedianSortedArrays(nums1, nums2);
            cout<<"result: "<<result<<endl;
        }
    }
    return 0;
}
