class Solution {
public:
    int toInt(const vector<int>& cells) {
        int result = 0;
        for (int i = 0; i < cells.size(); ++i) {
            result |= (cells[i] << i);
        }
        return result;
    }
    
    vector<int> nextState(const vector<int>& cells) {
        vector<int> next(cells.size(), 0);
        for (int i = 1; i < cells.size() - 1; ++i) {
            next[i] = cells[i - 1] == cells[i + 1];
        }
        return next;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if (n == 0) {
            return cells;
        }

        map<int, vector<int>> cellMap;
        vector<int> cellIndex;
        int cycleLength = 0;
        int state = toInt(cells);
        
        while (n > 0) {
            if (cellMap.find(state) == cellMap.end()) {
                cellMap[state] = cells;
                cellIndex.push_back(state);
            } else {
                cycleLength = cellIndex.size() - distance(cellIndex.begin(), find(cellIndex.begin(), cellIndex.end(), state));
                int remainingCycles = n % cycleLength;
                return cellMap[cellIndex[cellIndex.size()-cycleLength+remainingCycles]];
            }
            cells = nextState(cells);
            state = toInt(cells);
            --n;
        }
        return cells;
    }
};
