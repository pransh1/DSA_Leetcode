class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        int i=0;
        int j=0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        while(i<s.size() && j < t.size()) {
            if(s[i] != t[j]) return t[j];
            i++;
            j++;
        }
        return t.back();
    }
};