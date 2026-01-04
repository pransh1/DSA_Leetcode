class Solution {
public:
    int MOD = 1e9 + 7;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    vector<vector<int>> m;
    int solve(int n, int prev) {
        if(n == 0) return 1; // means all possible patterns are printed

        if(m[n][prev] != -1) return m[n][prev];
        int result = 0;
        string last = states[prev];
        for(int curr=0; curr<12; curr++) {
            if(curr == prev) continue;
            string currPattern = states[curr];
            bool conflict = false;
            for(int col=0;col<3;col++){
                if(currPattern[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }
            if(!conflict) {
                result = (result + solve(n-1, curr)) % MOD;
            }
        }
        return m[n][prev] = result;
    }

    int numOfWays(int n) {
        m.resize(n, vector<int>(12, -1));
        int result = 0;

        for(int i=0;i<12;i++) { // choosing 1st row
            result = (result + solve( n - 1, i ) ) % MOD; // remaining n-1 rows
        }    

        return result;
    }
};