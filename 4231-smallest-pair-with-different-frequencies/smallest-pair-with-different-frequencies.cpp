class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq; //( to store freq of all values )
        
        // Count frequency of every number
        for(auto a : nums ) {
            freq[a]++;
        }

        // Vector to store distinct numbers present in the array
        vector<int> pairs;
        for(auto &p : freq) {
            // Extract unique values from the frequency map
            pairs.push_back(p.first);
        }

        // Sort the unique values so we naturally try the smallest x first
        sort(pairs.begin(), pairs.end());

        int m = pairs.size();

        // Try all possible pairs (x, y)
        // Since the array is sorted, the first valid pair automatically
        // satisfies the condition:
        //   - smallest possible x
        //   - smallest possible y for that x
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                int x = pairs[i];
                int y = pairs[j];

                // Check if their frequencies are different
                if(freq[x] != freq[y]) {
                    // If yes, return the pair immediately
                    return {x, y};
                }
            }
        }
        // If no such pair exists
        return {-1, -1};
    }
};