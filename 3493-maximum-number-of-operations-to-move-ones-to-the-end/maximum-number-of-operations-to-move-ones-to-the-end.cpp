class Solution {
public:
    long long maxOperations(string s) {
        long long ones = 0;
        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else if (i + 1 == n || s[i + 1] == '1') {
                // this zero is the end of a zero-block -> count it
                ans += ones;
            }
        }

        return ans; // return long long to be safe for large counts
    }
};