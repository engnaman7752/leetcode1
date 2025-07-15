class Solution {
public:
    bool isValid(string word) {
        if (word.size() <= 2) return false;

        bool ans = false;  
        bool ans2 = false;  

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '@' || word[i] == '#' || word[i] == '$') return false;

            if (isalpha(word[i])) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
                    word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
                    ans = true;
                } else {
                    ans2 = true;
                }
            }
        }

        return ans && ans2;
    }
};
