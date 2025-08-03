#define ll long long
class Solution {
public:
    ll minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int>mp;
        int minEle = INT_MAX;
        for(int &x : basket1) {
            mp[x]++;
            minEle = min(minEle, x);
        } 

        for(int &x : basket2) {
            mp[x]--;
            minEle = min(minEle, x);
        }

        vector<int> finalList;
        for(auto& it : mp) {
            int cost = it.first;
            int count = it.second;

            if(count == 0) continue;
            if(count %2 != 0) return -1;
            for(int c = 1; c <= abs(count)/2; c++) {
                finalList.push_back(cost);
            }
        }

        sort(finalList.begin(), finalList.end());
        ll result = 0;
        for(int i=0;i<finalList.size()/2; i++) {
            result += min(finalList[i], minEle*2);
        }
        return result;
    }
};