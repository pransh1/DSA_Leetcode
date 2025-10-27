class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;

        for(auto it = bank.begin(); it != bank.end(); ++it) {
            int count = 0;
            for(auto jt = it->begin(); jt != it->end(); ++jt) {
                if(*jt == '1') {
                    count++;
                }
            }
            if(count != 0) {
                ans += prev*count;
                prev = count;
            }
        }
        return ans;
    }
};