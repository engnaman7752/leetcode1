class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string l = dominoes, r = dominoes;

        
        for (int t = 0; t < n; t++) {
            string temp = l;
            for (int i = 0; i < n; i++) {
                if (i < n - 1 && l[i] == '.' && l[i + 1] == 'L')
                    temp[i] = 'L';
                if (i > 0 && l[i] == '.' && l[i - 1] == 'R')
                    temp[i] = 'R';
            }
            if (temp == l) break;
            l = temp;
        }
        for (int t = 0; t < n; t++) {
            string temp = r;
            for (int i = n - 1; i >= 0; i--) {
                if (i > 0 && r[i] == '.' && r[i - 1] == 'R')
                    temp[i] = 'R';
                if (i < n - 1 && r[i] == '.' && r[i + 1] == 'L')
                    temp[i] = 'L';
                
            }
            if (temp == r) break;
            r = temp;
        }
        for (int i = 0; i < n;) {
            if (l[i] != r[i]) {
                int index = i, count = 0;
                while (i < n && l[i] != r[i]) {
                    i++;
                    count++;
                }
                for (int j = index; j < index + (count / 2); j++)
                    dominoes[j] = 'R';
                if (count % 2 == 1)
                    dominoes[index + count / 2] = '.';
                for (int j = index + (count + 1) / 2; j < index + count; j++)
                    dominoes[j] = 'L';
            } else {
                dominoes[i] = l[i];
                i++;
            }
        }

        return dominoes;
    }
};
