class Solution {
public:
    string mergeCharacters(string s, int k) {

        while(true) {

            bool isMerged = false;

            for(int i = 0; i < s.size(); i++) {

                for(int j = i + 1; j < s.size(); j++) {

                    if(s[i] == s[j] && j - i <= k) {

                        s.erase(j,1);
                        isMerged = true;
                        break;
                    }
                }

                if(isMerged) break;
            }

            if(!isMerged) break;
        }

        return s;
    }
};