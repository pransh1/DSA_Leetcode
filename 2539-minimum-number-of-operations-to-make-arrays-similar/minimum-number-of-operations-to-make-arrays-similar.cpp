class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> even, odd, t_even, t_odd;
        
        for(auto& i : nums){
            if(i % 2==0) even.push_back(i);
            else odd.push_back(i);
        }

        for(auto& i : target){
            if(i % 2==0) t_even.push_back(i);
            else t_odd.push_back(i);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        sort(t_even.begin(), t_even.end());
        sort(t_odd.begin(), t_odd.end());
        long long operations = 0;

        for(int i=0; i<even.size(); i++) {
            if(t_even[i] > even[i]) {
                operations += (t_even[i] - even[i])/2;
            }
        }
        for(int i=0; i<odd.size(); i++) {
            if(t_odd[i] > odd[i]) {
                operations += (t_odd[i] - odd[i])/2;
            }
        }
        return operations;
    }
};