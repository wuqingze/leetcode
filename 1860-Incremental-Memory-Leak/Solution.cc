class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int m = 1;
        while(m<= memory1 or m<=memory2){
            if(memory1 >= memory2){
                memory1 -= m;
            }else{
                memory2 -= m;
            }
            m += 1;
        }
        return {m, memory1, memory2};
    }
};
