class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int ret = 0xffffffff;
        // for(int i=left; i<=right;i++){
        //     ret &= i;
        //     if(ret == 0 or i==0x7fffffff) break;
        // }
        // return ret;
        return left == right?left:rangeBitwiseAnd(left>>1, right>>1)<<1;
    }
};
