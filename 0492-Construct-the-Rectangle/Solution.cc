class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = sqrt(area);
        while(l>0){
            if((area/l)*l == area){
                return {area/l, l};
            }else{
                l -= 1;
            }
        }
        return {};
    }
};
