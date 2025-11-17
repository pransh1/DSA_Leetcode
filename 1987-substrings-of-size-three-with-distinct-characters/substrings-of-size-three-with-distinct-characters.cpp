// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         int count = 0;
//         int l = 0;

//         for(int r=0;r<s.size(); r++) {
//             unordered_set<char> seen;
//             if(r-l+1 == 3) {
//                 seen.insert(s[l]);
//                 seen.insert(s[l+1]);
//                 seen.insert(s[l+2]);
//                 if(seen.size() == 3) count++;
//                 l++;
//             }

//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         int n = s.length(), i = 0, count = 0;
//         while (i + 2 < n) {
//             if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
//                 ++count;
//             }
//             ++i;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if (n < 3) return 0;

        int ans = 0;

        for (int i = 0; i + 2 < n; i++) {
            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];

            if (a != b && b != c && a != c)
                ans++;
        }

        return ans;
    }
};
