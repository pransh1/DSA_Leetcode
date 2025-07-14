class Solution {
public:

    void parenthesis(int n, int open, int close, string possible, vector<string>& ans) {
        if(open == n && close == n) {
            ans.push_back(possible);
            return;
        }
        if(open > n || close > open) return;

        parenthesis(n, open+1, close, possible + "(", ans);
        parenthesis(n, open, close+1, possible + ")", ans);
    }

    vector<string> generateParenthesis(int n) {
       string isPossible;
       vector<string> ans;
       parenthesis(n, 0, 0, isPossible, ans);
       return ans;
    }
};