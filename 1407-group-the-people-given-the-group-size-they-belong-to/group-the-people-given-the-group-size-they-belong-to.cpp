class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> totalGroup;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            mp[size].push_back(i);
        }

        for (auto& it : mp) {
            int groupSize = it.first;
            vector<int>& people = it.second;

            for (int i = 0; i < people.size(); i += groupSize) {
                vector<int> group;
                for (int j = 0; j < groupSize; j++) {
                    group.push_back(people[i + j]);
                }
                totalGroup.push_back(group);
            }
        }

        return totalGroup;
    }
};
