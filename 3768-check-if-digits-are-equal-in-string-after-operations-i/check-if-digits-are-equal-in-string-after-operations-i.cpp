class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(s.size() > 2) {
            string sub = "";
            for(int i=0;i+1<n;i++) {
                int d1 = s[i] - '0';
                int d2 = s[i + 1] - '0';
                int sum = (d1 + d2) % 10;
                sub.push_back(sum + '0');
            }
            s = sub;
            n = s.size();
        } 
        return s[0] == s[1];
    }
};