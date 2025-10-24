class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int rank = 1;
        vector<string> result(n);
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++) {
            pq.push({score[i], i});
        }

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int ranking = top.second;
            if(rank == 1) result[ranking] = "Gold Medal";
            else if(rank == 2) result[ranking] = "Silver Medal";
            else if(rank == 3) result[ranking] = "Bronze Medal";
            else result[ranking] = to_string(rank);

            rank++;
        }
        return result;
    }
};