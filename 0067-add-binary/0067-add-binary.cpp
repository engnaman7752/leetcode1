class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0 && a[i] == '1') sum++;
            if (j >= 0 && b[j] == '1') sum++;
            ans.push_back((sum % 2) + '0'); 
            carry = sum / 2;                
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
