class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> order = {
            {"electronics" , 0},
            {"grocery" , 1},
            {"pharmacy" , 2},
            {"restaurant" , 3}
        };

        vector<pair<int, string>> valid;

        for(int i=0;i<code.size(); i++) {
            if(code[i].empty()) continue;

            bool ok = true;
            for(char c : code[i]) {
                if(!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;

            if(order.find(businessLine[i]) == order.end()) continue;

            if(!isActive[i]) continue;

            valid.push_back({order[businessLine[i]], code[i]});

        }

        sort(valid.begin(), valid.end(), [](auto &a, auto &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> answer;
        for(auto &p : valid) {
            answer.push_back(p.second);
        }
        return answer;
    }
};