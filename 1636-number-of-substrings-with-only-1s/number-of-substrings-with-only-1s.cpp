class Solution {
public:
    int numSub(string s) {
        long long ans =0;
        long long window = 0;
        long long MOD = 1e9+7;
        for(char c : s) {
            if(c == '1') {
                window++;
                ans = (ans + window) % MOD;
            }
            else{
                window = 0;
            }
        }
        return ans;
    }
};