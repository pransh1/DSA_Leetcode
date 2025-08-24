// class Solution {
// public:
//     string predictPartyVictory(string senate) {
//         if(senate.length() <= 2) {
//             if(senate[0] == 'R') return "Radiant";
//             else return "Dire";
//         }
//         if(senate.size() % 2 == 0) {
//             if(senate[0] == 'R') return "Radiant";
//             else return "Dire";
//         }
//         else {
//             if(senate.size() % 2 != 0) {
//                 if(senate[senate.size() - 1] == 'R') return "Radiant";
//             }
//         }
//         return "Dire";
//     }
// };

#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();
            if (r < d) {
                radiant.push(r + n);
            } else {
                dire.push(d + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
