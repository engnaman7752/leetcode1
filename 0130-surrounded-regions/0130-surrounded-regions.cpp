class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int,int>>q;
        int row=0;
        int col=0;
        while(col<board[0].size())
        {
            if(board[row][col]=='O'&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            col++;
        }
        col=col-1;
         while(row<board.size())
        {
            if(board[row][col]=='O'&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            row++;
        }
        col=0;
        row=1;
        while(row<board.size())
        {
            if(board[row][col]=='O'&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            row++;
        }
        row--;
        while(col<board[0].size())
        {
            if(board[row][col]=='O'&&vis[row][col]==false)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
            col++;
        }
        vector<int>decol{-1,0,1,0};
            vector<int>derow{0,-1,0,1};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int p=0;p<4;p++)
            {
                int ncol=j+decol[p];
                int nrow=i+derow[p];
                if (nrow >= 0 && nrow < vis.size() && ncol >= 0 && ncol < vis[0].size() && board[nrow][ncol] == 'O' && vis[nrow][ncol] == false)
                 {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=true;
                }
            }

        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(vis[i][j]==false)
                board[i][j]='X';
            }
        }




        

    }
};