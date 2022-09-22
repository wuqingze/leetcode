class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A = (ay2-ay1)*(ax2-ax1);
        int B = (by2-by1)*(bx2-bx1);
        
        if(ax2<=bx1 or bx2<=ax1 or ay2<=by1 or ay1>=by2){
            return A+B;
        }
        
        if((ay1>=by1 and ay2<=by2 and ax1>=bx1 and ax2<=bx2)
           or (by1>=ay1 and by2<=ay2 and bx1>=ax1 and bx2<=ax2)){
            return max(A,B);
        }
        
        int x2 = min(ax2,bx2);
        int y2 = min(by2, ay2);
        int x1 = max(ax1, bx1);
        int y1 = max(ay1, by1);
        return (A+B)-(y2-y1)*(x2-x1);
    }
};
