class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> t;
    int M;
    vector<string> columnStates;
    void generateColumnState(string currState, int len, char prevColor) {
        if(len==M) {
            columnStates.push_back(currState);
            return;
        }
        
        for(char ch : {'R', 'G', 'B'}) {
            if(ch == prevColor) continue;

            generateColumnState(currState + ch, len + 1, ch);
        }
    }

    int solve(int prevStateIdx, int remainingCol) {
        if(remainingCol == 0) {
            return 1;
        }
        if(t[prevStateIdx][remainingCol] != -1) return t[prevStateIdx][remainingCol];
        int result = 0;
        string prevState = columnStates[prevStateIdx];
        for(int i=0;i<columnStates.size(); i++) {
            if(i == prevStateIdx) continue;
            string curr = columnStates[i];
            bool isValid = false;
            for(int j=0;j<M;j++) {
                if(prevState[j] == curr[j]) {
                    isValid = true;
                    break;
                }
            }
            if(!isValid) {
                result = (result + solve(i, remainingCol-1)) % MOD;
            }
        }
        return t[prevStateIdx][remainingCol] = result;
    }

    int colorTheGrid(int m, int n) {
        M = m;
        int result = 0;
        generateColumnState("", 0, '#');
        t.resize(columnStates.size(), vector<int>(n, -1));

        for(int i=0;i<columnStates.size(); i++) {
            result = (result + solve(i, n-1)) % MOD;
        }
        return result;
    }
};