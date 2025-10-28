class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        int count = 0;

        for(int num : stones) {
            pq.push(num);
        }
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x != y) {
                pq.push(x-y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};