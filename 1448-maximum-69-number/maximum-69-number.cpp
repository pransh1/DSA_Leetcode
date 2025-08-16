class Solution {
public:
    int maximum69Number (int num) {
        string x = to_string(num);
        string ans = x;
        for(int i=0;i<x.size();i++) {
            if(x[i] == '6') {
                x[i] = '9';
                ans = max(ans, x);
                x[i] = '6';
            }
        }
        return stoi(ans);
    }
};