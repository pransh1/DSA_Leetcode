// class Solution {
// public:
//     string reorganizeString(string s) {
//         for(int i=0;i<s.length()-1;) {
//             bool swapped = false;
//             int j = i+1;
//             while (j < s.length()) {
//                 if (s[i] == s[j]) {
//                     j++; 
//                 } else {
//                     swap(s[i + 1], s[j]); 
//                     swapped = true;
//                     break;
//                 }
//             }
//             if (!swapped && s[i] == s[i + 1]) {
//                 return "";
//             }
//             i++;  
//         }
//         return s;
//     }
// };

class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<char, int>> vec(26);
        int n = s.length();

        // Step 1: Fill character frequencies
        for (char ch : s) {
            vec[ch - 'a'].first = ch;
            vec[ch - 'a'].second++;
        }

        // Step 2: Remove zero frequency entries
        vector<pair<char, int>> freq;
        for (auto &p : vec) {
            if (p.second > 0) {
                freq.push_back(p);
            }
        }

        // Step 3: Check if reorganization is possible
        for (auto &[ch, cnt] : freq) {
            if (cnt > (n + 1) / 2) return "";
        }

        string result;

        // Step 4: Build string by always picking highest and lowest frequency
        while (!freq.empty()) {
            // Sort descending by freq
            sort(freq.begin(), freq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second > b.second;
            });

            // Add most frequent
            result += freq[0].first;
            freq[0].second--;

            // Optional second character (to avoid adjacent duplicates)
            if (freq.size() > 1 && freq.back().second > 0) {
                result += freq.back().first;
                freq.back().second--;
            }

            // Remove any exhausted characters
            if (freq[0].second == 0) freq.erase(freq.begin());
            if (!freq.empty() && freq.back().second == 0 && (freq.size() == 1 || freq.back() != freq[0])) {
                freq.pop_back();
            }
        }

        return result;
    }
};
