class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int cnt = 0;
        bool found = false;

        for(int i=0; i<=n; i++) {
            if(i==n || text[i] == ' ') {
                if(!found) cnt++;
                found = false;
            }
            else {
                if(brokenLetters.find(text[i]) != string::npos ) {
                    found = true;
                }
            }
        }
        return cnt;
    }
};

