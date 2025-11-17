class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int l=0;l<n;l++) {
            unordered_map<char, int> mp;
            for(int r=l;r<n;r++) {
                char ch = s[r];
                if(mp[ch] > 0) break;
                mp[ch]++;
                int len = r-l+1;
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};