class Solution {
public:
    int differenceOfSums(int n, int m) {
        vector<int> div;
        vector<int> non_div;
        for(int i=1; i<=n; i++) {
            if(i%m == 0) {
                div.push_back(i);
            }
            else {
                non_div.push_back(i);
            }
        }

        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<div.size(); i++) {
            sum1 += div[i];
        }
        for(int i=0;i<non_div.size(); i++) {
            sum2 += non_div[i];
        }

        return sum2 - sum1;
    }
};