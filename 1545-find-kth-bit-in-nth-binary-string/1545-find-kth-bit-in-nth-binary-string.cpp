class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";    
        for(int i = 2; i <= n; i++) {
            string temp = s;
            for(char &c : temp)
                c = (c == '0') ? '1' : '0';
            reverse(temp.begin(), temp.end());     
            s = s + "1" + temp;
        }    
        return s[k-1];  
    }
};