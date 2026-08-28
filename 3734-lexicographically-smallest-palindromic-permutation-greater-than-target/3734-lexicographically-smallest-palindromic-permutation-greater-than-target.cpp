class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for(char c : s) count[c - 'a']++;
        
        int odd_count = 0;
        char mid_char = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] % 2 != 0) {
                odd_count++;
                mid_char = i + 'a';
            }
        }
        
        // A palindrome can have at most one character with an odd frequency
        if(odd_count > 1) return "";
        
        vector<int> half_count(26, 0);
        for(int i = 0; i < 26; i++) half_count[i] = count[i] / 2;
        
        int M = n / 2;
        
        // 1. Find how much of target's prefix we can exactly match
        int match_len = 0;
        vector<int> temp_count = half_count;
        for(int i = 0; i < M; i++) {
            int c = target[i] - 'a';
            if(temp_count[c] > 0) {
                temp_count[c]--;
                match_len++;
            } else {
                break;
            }
        }
        
        // 2. Check Exact Match of the left half
        if (match_len == M) {
            string L = target.substr(0, M);
            string P = L;
            if (n % 2 != 0) P += mid_char;
            string R = L;
            reverse(R.begin(), R.end());
            P += R;
            
            if (P > target) return P;
        }
        
        // 3. Find the rightmost divergence point
        int start_i = min(M - 1, match_len);
        vector<int> avail = half_count;
        
        // Pre-consume characters for target[0 ... start_i - 1]
        for (int k = 0; k < start_i; k++) {
            avail[target[k] - 'a']--;
        }
        
        // Iterate backwards to find the optimal divergence
        for (int i = start_i; i >= 0; i--) {
            char req = target[i];
            char picked = 0;
            
            // Find the smallest available character STRICTLY GREATER than target[i]
            for (int c = (req - 'a') + 1; c < 26; c++) {
                if (avail[c] > 0) {
                    picked = c + 'a';
                    avail[c]--;
                    break;
                }
            }
            
            if (picked != 0) {
                string L = target.substr(0, i);
                L += picked;
                
                // Greedily pick the smallest characters for the rest of the left half
                for (int c = 0; c < 26; c++) {
                    while (avail[c] > 0) {
                        L += (c + 'a');
                        avail[c]--;
                    }
                }
                
                // Construct and return the full palindrome
                string P = L;
                if (n % 2 != 0) P += mid_char;
                string R = L;
                reverse(R.begin(), R.end());
                P += R;
                
                return P;
            }
            
            // Backtrack for the next iteration (i - 1)
            // Restore the character we would have used at index i - 1
            if (i > 0) {
                avail[target[i - 1] - 'a']++;
            }
        }
        
        return "";
    }
};