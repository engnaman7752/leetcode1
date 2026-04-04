class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        if(rows==1)return e;
        int t=e.size();
        if(t==0)return e;
        int cols=t/rows;
        vector<string>mat;
        for(int i=0;i<t;i++){
            if((i+1)%cols==0){
                string k=e.substr(i-cols+1,cols);
                mat.push_back(k);
            }
        }
        string ans;
        for(int i=0;i<cols;i++){
            int col=i;
            int r=0;
            while(r<rows && col<cols){
                ans.push_back(mat[r][col]);
                r++;col++;
            }
        }
        int l=ans.size();
        int i=l-1;
    while(ans[i]==' ')i--;
    return ans.substr(0,i+1);
    }
};