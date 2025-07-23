class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char ch1 = 'a';
        char ch2 = 'b';
        if(x<y) {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }

        int score = 0;
        stack<char> st;
        for(char c : s) {
            if(!st.empty() && st.top() == ch1 && c == ch2) {
                st.pop();
                score += x;
            }
            else {
                st.push(c);
            }
        }
        string remaining;
        while(!st.empty()){
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        for(char c : remaining) {
            if(!st.empty() && st.top() == ch2 && c == ch1){
                st.pop();
                score += y;
            }
            else {
                st.push(c);
            }
        }
        return score;
    }
    
};