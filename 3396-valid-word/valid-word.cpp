class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool isVowel = false;
        bool isConsonent = false;
        for(char c : word ) {
            if( ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z') ) {
                if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    isVowel = true;
                }
                else isConsonent = true;
            }
            else if(!isdigit(c)){
                return false;
            }
        }
        return isVowel && isConsonent;
    }
};