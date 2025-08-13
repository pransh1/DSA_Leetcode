class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size()-1;
        while(l <= r) {
            // face-up
            if(tokens[l] <= power){
                power -= tokens[l++];
                score++;
            }
            // face-down
            else if(score > 0 ){
                power += tokens[r--];
                score--;
            }
            else return maxScore;
            maxScore = max(maxScore, score);
        } 
        return maxScore;
    }
};