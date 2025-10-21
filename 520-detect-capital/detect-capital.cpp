class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true, allLower = true;

        for(char c : word) {
            if(!isupper(c)) allUpper = false;
            if(!islower(c)) allLower = false;
        }

        if(allUpper) return true;
        if(allLower) return true;

        if(isupper(word[0])) {
            for(int i=1;i<word.size(); i++) {
                if(!islower(word[i])) return false;
            }
            return true;
        }
        return false;
    }
};