class Solution {
public:
    string largestGoodInteger(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
                string temp = s.substr(i,3);
                // if(temp > ans) ans = temp;
                ans = max(temp, ans);
            }
        }              
        return ans;       
    }
}; 