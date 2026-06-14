class Solution {
public:
    bool solve(int index,int i,int j,vector<vector<char>>& board, string& word){
         int n=board.size();
        int m=board[0].size();
        if(index==word.size())return true;
        if(i>=n || j>=m ||i<0 || j<0 ||board[i][j]!=word[index] )return false;
        board[i][j]='#';
        bool ans=solve(index+1,i+1,j,board,word)|
                 solve(index+1,i-1,j,board,word)|
                 solve(index+1,i,j+1,board,word)|
                 solve(index+1,i,j-1,board,word);
        board[i][j]=word[index];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,board,word))return true;
                }
            }
        }
        return false;
    }
};