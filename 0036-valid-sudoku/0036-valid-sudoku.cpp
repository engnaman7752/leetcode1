class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<char>st;
            for(int j=0;j<9;j++){
                char x=board[i][j];
                if(x!='.'){
                    if(st.find(x)==st.end())
                    st.insert(x);
                    else
                    return false;
                }
            }
        }
           for(int i=0;i<9;i++){
            set<char>st;
            for(int j=0;j<9;j++){
                char x=board[j][i];
                if(x!='.'){
                    if(st.find(x)==st.end())
                    st.insert(x);
                    else
                    return false;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<char>st;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        char x=board[i+k][j+l];
                         if(x!='.'){
                    if(st.find(x)==st.end())
                    st.insert(x);
                    else
                    return false;

                        }
                    }
                }
            }
        }
        return true;
    }
};