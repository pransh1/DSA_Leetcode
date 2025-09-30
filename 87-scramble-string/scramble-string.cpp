class Solution {
public:
    unordered_map<string, bool> dp;
    bool isPossible(string& s1, string& s2) {
        int n = s1.size();
        if(s1 == s2) return true;
        if(n != s2.size()) return false;
        string key = s1 + '#' + s2;
        if(dp.find(key) != dp.end()) return dp[key];
        for(int i=1; i<n; i++) {
            // left and right part -> s1
            string left1 = s1.substr(0, i);
            string right1 = s1.substr(i);

            // left and right part -> s2
            string left2 = s2.substr(0, i);
            string right2 = s2.substr(i);

            // before swap
            if(isPossible(left1, left2) && isPossible(right1, right2)) return dp[key] = true;
            // after swap

            // left and right part -> s1
            string leftSwap1 = s1.substr(0, n-i);
            string rightSwap1 = s1.substr(n-i);

            // left and right part -> s2
            string leftSwap2 = s2.substr(i);
            string rightSwap2 = s2.substr(0, i);

            if(isPossible(leftSwap1, leftSwap2)&&isPossible(rightSwap1, rightSwap2)) return dp[key] = true;
        }
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return isPossible(s1, s2);
    }
};