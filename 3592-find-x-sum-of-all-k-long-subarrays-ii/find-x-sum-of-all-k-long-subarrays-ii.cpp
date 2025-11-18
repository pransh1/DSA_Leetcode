#define ll long long
class Solution {
public:
    struct Node {
    int freq, val;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        if(a.freq != b.freq) {
            return a.freq > b.freq;
        }
        return a.val > b.val;
    }
};

// push from remaining -> topX
void best (set<Node, Cmp>& topX, set<Node, Cmp>& remaining, ll& Xsum) {
    if(remaining.empty()) return;
    auto it = remaining.begin();
    Xsum += 1LL* it->val*it->freq;
    topX.insert(*it);
    remaining.erase(it);
}

//from topX → rest
void remove(set<Node, Cmp>& topX, set<Node, Cmp>& remaining, ll& Xsum) {
    if(topX.empty()) return;
    auto it = prev(topX.end());
    Xsum -= 1LL * it->val * it->freq;
    remaining.insert(*it);
    topX.erase(it);

}
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<ll> ans;
        // freq
        unordered_map<int,int> freq;
        // topX elem
        set<Node, Cmp> topX, remaining;
        ll xSum = 0;

        auto rebalance = [&]() {
            // 1) fill topX until size x (promote best from remaining)
            while ((int)topX.size() < x && !remaining.empty()) {
                best(topX, remaining, xSum);
            }

            // 2) if remaining best > topX worst => swap them
            while(!remaining.empty() && !topX.empty()) {
                const Node& bestRem = *remaining.begin();
                const Node& worstTop = *prev(topX.end());
                Cmp cmp;
                if (cmp(bestRem, worstTop)) {
                    // bestRem better than worstTop -> swap
                    best(topX, remaining, xSum);
                    remove(topX, remaining, xSum);
                } 
                else {
                    break;
                }
            }
        };

        auto addVal = [&](int v) {
            int oldFreq = freq[v];
            int newFreq = ++freq[v];

            // remove old version 
            if(oldFreq > 0) {
                Node oldNode{oldFreq, v};
                if(topX.count(oldNode)) {
                    xSum -= 1LL * v * oldFreq;
                    topX.erase(oldNode);
                }
                else {
                    remaining.erase(oldNode);
                }
            }
            // put updated node into remaining first (not directly into topX)
            Node newNode{newFreq, v};
            remaining.insert(newNode);
            // rebalance sets to maintain topX as top x elements
            rebalance();
        };

        auto removeVal = [&](int v) {
            int oldFreq = freq[v];
            int newFreq = oldFreq - 1;

            // remove old node
            Node oldNode{oldFreq, v};
            if(topX.count(oldNode)) {
                xSum -= 1LL*v*oldFreq;
                topX.erase(oldNode);
            }
            else{
                remaining.erase(oldNode);
            }

            if(newFreq == 0) {
                freq.erase(v);
            }
            else {
                freq[v] = newFreq;
                Node newNode{newFreq, v};
                remaining.insert(newNode);
                
            }

            // rebalance after removal
            rebalance();
        };

        int i = 0;

        for(int j=0;j<n;j++) {
            addVal(nums[j]);

            if(j - i + 1 < k) {
                continue;
            }

            ans.push_back(xSum);

            removeVal(nums[i]);

            i++;
        }
        return ans;
    }
};