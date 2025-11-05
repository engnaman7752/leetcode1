class Helper {
public:
    long long ansSum = 0;
    int x;
    unordered_map<int,int> mp;
    set<pair<int,int>> big, small; 

    Helper(int _x) { x = _x; }

    void insert(int num) {
        if (mp[num]) removePair({mp[num], num});
        mp[num]++;
        addPair({mp[num], num});
    }

    void erase(int num) {
        removePair({mp[num], num});
        mp[num]--;
        if (mp[num] > 0) addPair({mp[num], num});
    }

    long long getSum() { return ansSum; }

private:
    void addPair(pair<int,int> p) {
        if ((int)big.size() < x || p > *big.begin()) {
            ansSum += 1LL * p.first * p.second;
            big.insert(p);
            if ((int)big.size() > x) {
                auto it = big.begin();
                ansSum -= 1LL * it->first * it->second;
                small.insert(*it);
                big.erase(it);
            }
        } else {
            small.insert(p);
        }
    }

    
    void removePair(pair<int,int> p) {
        if (big.count(p)) {
            ansSum -= 1LL * p.first * p.second;
            big.erase(p);
            if (!small.empty()) {
                auto it = prev(small.end());
                ansSum += 1LL * it->first * it->second;
                big.insert(*it);
                small.erase(it);
            }
        } else {
            small.erase(p);
        }
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        Helper help(x);
        vector<long long> ans;
        for (int r = 0; r < n; r++) {
            help.insert(nums[r]);
            if (r >= k) help.erase(nums[r - k]);
            if (r >= k - 1) ans.push_back(help.getSum());
        }
        return ans;
    }
};
