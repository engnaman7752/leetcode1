class Solution {
public:
    int mod = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& arr, vector<int>& brr) {
        set<long long> a;     
        vector<long long> b; 
        arr.push_back(1);
        arr.push_back(m);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                a.insert(arr[j] - arr[i]);
            }
        }
        brr.push_back(1);
        brr.push_back(n);
        sort(brr.begin(), brr.end());
        for (int i = 0; i < brr.size(); i++) {
            for (int j = i + 1; j < brr.size(); j++) {
                b.push_back(brr[j] - brr[i]);
            }
        }

        sort(b.rbegin(), b.rend());
        for (long long x : b) {
            if (a.count(x)) {
                return (x * x) % mod;
            }
        }
        return -1;
    }
};
