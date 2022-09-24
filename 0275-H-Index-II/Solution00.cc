class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h;
        int i=0;
        int j = n-1;
        int mid;
        while(i<=j){
            mid = i+(j-i)/2;
            h = n-mid-1;
            if(citations[mid]>h){
                if(mid == 0){
                    return h+1;
                }else{
                    if(citations[mid-1]<=(h+1)){
                        return h+1;
                    }else{
                        j = mid-1;
                    }
                }
            }else{
                i = mid + 1;
            }
        }
        return 0;

    }
};
