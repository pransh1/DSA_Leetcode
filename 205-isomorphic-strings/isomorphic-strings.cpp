class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, char> mp1, mp2;
        for(int i=0;i<s.size(); i++) {
            // if already mapped and not same
            if(mp1.count( s[i] ) && mp1[ s[i] ] != t[i] ) return false;
            if(mp2.count( t[i] ) && mp2[ t[i] ] != s[i] ) return false;

            mp1[ s[i] ] = t[i];
            mp2[ t[i] ] = s[i];
        }
        return true;
    }
};