// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxLen = 0;

//         for(int l=0;l<n;l++) {
//             unordered_map<char, int> mp;
//             for(int r=l;r<n;r++) {
//                 char ch = s[r];
//                 if(mp[ch] > 0) break;
//                 mp[ch]++;
//                 int len = r-l+1;
//                 maxLen = max(len, maxLen);
//             }
//         }
//         return maxLen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            // if character already in window, shrink from left
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
