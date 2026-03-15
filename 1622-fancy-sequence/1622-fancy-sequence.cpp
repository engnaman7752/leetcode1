class Fancy {
public:
    vector<long long> v;
    long long a = 0, b = 1;
    int mod = 1e9 + 7;

    long long modPow(long long x, long long y) {
        long long res = 1;
        x %= mod;
        while (y) {
            if (y & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            y >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - a + mod) % mod;
        long long inv = modPow(b, mod - 2);
        v.push_back((x * inv) % mod);
    }

    void addAll(int inc) {
        a = (a + inc) % mod;
    }

    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        return ((v[idx] * b) % mod + a) % mod;
    }
};