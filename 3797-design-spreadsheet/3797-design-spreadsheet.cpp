class Spreadsheet {
public:
map<char,vector<int>>mp;
int len;
    Spreadsheet(int rows) {
        len=rows;
        for(char ch='A';ch<='Z';ch++){
            mp[ch].assign(len, 0);
        }
    }
    
    void setCell(string cell, int value) {
        char ch=cell[0];
        int index=stoi(cell.substr(1));
        mp[ch][index-1]=value;
    }
    
    void resetCell(string cell) {
         char ch=cell[0];
         int index=stoi(cell.substr(1));
         mp[ch][index-1]=0;
    }
    
    int getValue(string formula) {
    char ch = formula[1];
    int ans = 0;
    int i = 0;

    if (!(ch >= 'A' && ch <= 'Z')) { 
        string temp = "";
        i = 1;
        while (formula[i] != '+') {
            temp += formula[i];
            i++;
        }
        ans += stoi(temp);
    } else {
        string temp = "";
        i = 2;
        while (formula[i] != '+') {
            temp += formula[i];
            i++;
        }
        int index = stoi(temp);
        ans += mp[ch][index - 1];
    }

    i++; 
    char ch2 = formula[i];

    if (!(ch2 >= 'A' && ch2 <= 'Z')) {  
        string temp = "";
        while (i < formula.size()) {
            temp += formula[i];
            i++;
        }
        ans += stoi(temp);
    } else {
        string temp = "";
        i = i + 1;
        while (i < formula.size()) {
            temp += formula[i];
            i++;
        }
        int index = stoi(temp);
        ans += mp[ch2][index - 1];
    }

    return ans;
}
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */