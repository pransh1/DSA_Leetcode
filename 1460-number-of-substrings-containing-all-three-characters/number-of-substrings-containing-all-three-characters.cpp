class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<char, int> mp;

        while(r<s.size()) {
            mp[s[r]]++;

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                cnt += s.size() - r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
        // int cnt = 0;
        // int lastseen[] = {-1,-1,-1};
        // for(int i=0;i<s.size();i++) {
        //     lastseen[s[i] - 'a'] = i;
        //     if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
        //         cnt = cnt + (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
        //     }
        // }
        // return cnt;
    }
};