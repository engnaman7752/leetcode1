class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');
        
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        
       
        ans += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return ans;
        
        ans.push_back('.');
        map<long long,int> mp;
        string frac;
        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                frac.insert(mp[rem], "(");
                frac.push_back(')');
                break;
            }
            mp[rem] = frac.size();
            rem *= 10;
            frac.push_back((rem / den) + '0');
            rem %= den;
        }
        
        ans += frac;
        return ans;
    }
};
