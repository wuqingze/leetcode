#include <iostream>
#include <vector>
#include <limits.h>
#include <sstream>
using namespace std;
class Solution{
    public:
        static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            int m = nums2.size();
            if(n==0){if(n%2==0) return double(nums2[m/2]+nums2[(m-1)/2])/2; else return double(nums2[m/2]);}
            if(m==0){if(m%2==0) return double(nums1[n/2]+nums1[(n-1)/2])/2; else return double(nums1[n/2]);}

            int l = 0, r = n-1;
            double result;
            bool isEven = (n+m)%2==0;
            while(l<=r){
                int i = (r-l)/2 + l;
                int j = (m+n+1)/2 -2 - i;

                if(j<-1){r-=1; continue;}
                if(j>n){l+=1; continue;}

                int t1, t2, t3, t4;
                t1 = nums1[i];
                t2 = j==-1?INT_MIN:nums2[j];
                t3 = i==n-1?INT_MAX:nums1[i+1];
                t4 = j==m-1?INT_MAX:nums2[j+1];

                int A = t1>t2?t1:t2;
                int B = t3>t4?t4:t3;

                if(A<=B){
                    if(isEven) result = double(A+B)/2;
                    else result = double(A); 
                    break;
                }else{
                    if(nums1[i]>B){
                        r = (r-l)/2 + l - 1;
                    }else{
                        l = (r-l)/2 + l + 1;
                    }
                }
            }
            return result;
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
