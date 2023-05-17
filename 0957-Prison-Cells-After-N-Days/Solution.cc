class Solution {
public:
    int toint(vector<int>& cells){
        int result = 0;
        if(cells[0] == 1) result +=1;
        if(cells[1] == 1) result +=2;
        if(cells[2] == 1) result +=4;
        if(cells[3] == 1) result +=8;
        if(cells[4] == 1) result +=16;
        if(cells[5] == 1) result +=32;
        if(cells[6] == 1) result +=64;
        if(cells[7] == 1) result +=128;
        return result;
    }
    
    void transfer(vector<int>& cell1, vector<int>& cell2){
        cell2[0] = 0;
        cell2[7] = 0;
        for(int i=1;i<=6;i++){
            if(cell1[i-1]==0 and cell1[i+1]==0){
                cell2[i] = 1;
            }else if(cell1[i-1]==1 and cell1[i+1]==1){
                cell2[i] = 1;
            }else cell2[i] = 0;
        }
    }
    
    bool equal(vector<int>& l1, vector<int>&l2){
        for(int i=0;i<8;i++) if(l1[i] != l2[i]) return false;
        return true;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<int, vector<int>> cellmap;
        vector<int> cellindex;
        vector<int> cell1(cells.begin(), cells.end());
        vector<int> cell2(cells.begin(), cells.end());
        int cnt = n;
        while(n-->0){
            int key = toint(cell1);
            if(cellmap.find(key)==cellmap.end()){
                cellmap[key] = vector<int>(cell1.begin(), cell1.end());
                cellindex.push_back(key);
            }else{
                int i=0;
                int m = cellindex.size();
                for(;i<m;i++){
                    if(equal(cellmap[cellindex[i]], cell1)){
                        break;
                    }
                }
                int t = (cnt-m)%(m-i);
                return cellmap[cellindex[t+i]];
            }
            transfer(cell1, cell2);
            cell1 = cell2;
        }
        
        return cell1;
    }
};
