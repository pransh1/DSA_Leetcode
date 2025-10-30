class Solution {
public:
    unordered_map<string, int> mp;
    int solve(int i, int j, string& s1, string& s2) {
        if(i == s1.size () && j == s2.size()) return 0;
        // if s2 still has some val
        if(i == s1.size()) {
            int sum = 0;
            for(int k = j; k<s2.size(); k++) {
                sum += (int)s2[k];
            }
            return sum;
        } 
        // if s1 still has elements
        if(j==s2.size()) {
            int sum = 0;
            for(int k=i;k<s1.size(); k++) {
                sum += (int)s1[k];
            }
            return sum;
        }

        // create unique key for memoization
        string key = to_string(i) + "," + to_string(j);
        if (mp.count(key)) return mp[key];
        // if both same skip
        if(s1[i] == s2[j]) return solve(i+1, j+1, s1, s2);
        
        // either del from s1 first or s2
        int delS1 = (int)s1[i] + solve(i+1, j, s1, s2);
        int delS2 = (int)s2[j] + solve(i, j+1, s1, s2);
        return mp[key] = min(delS1, delS2);        
    }
    int minimumDeleteSum(string s1, string s2) {
        return solve(0, 0, s1, s2);
    }
};