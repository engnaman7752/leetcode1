class Solution {
    int mod=1e9+7;
    int memo[105][105];
    int dfs(int r,int c,int n,vector<vector<int>>& dis,vector<string>& board){
        if(r==n-1&&c==n-1)return 1;
        if(memo[r][c]!=-1)return memo[r][c];
        long long ways=0;
        int dr[]={1,0,1};
        int dc[]={0,1,1};
        int val=(board[r][c]=='E'||board[r][c]=='S')?0:(board[r][c]-'0');
        for(int i=0;i<3;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr<n&&nc<n&&board[nr][nc]!='X'){
                if(dis[r][c]==dis[nr][nc]+val){
                    ways=(ways+dfs(nr,nc,n,dis,board))%mod;
                }
            }
        }
        return memo[r][c]=ways;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MIN));
        priority_queue<tuple<int,int,int>> pq;
        dis[n-1][n-1]=0;
        pq.push({0,n-1,n-1});
        int dr[]={0,-1,-1};
        int dc[]={-1,0,-1};
        while(!pq.empty()){
            auto [sum,r,c]=pq.top();
            pq.pop();
            if(sum<dis[r][c])continue;
            for(int i=0;i<3;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&board[nr][nc]!='X'){
                    int val=(board[nr][nc]=='E'||board[nr][nc]=='S')?0:(board[nr][nc]-'0');
                    if(sum+val>dis[nr][nc]){
                        dis[nr][nc]=sum+val;
                        pq.push({dis[nr][nc],nr,nc});
                    }
                }
            }
        }
        if(dis[0][0]==INT_MIN)return {0,0};
        memset(memo,-1,sizeof(memo));
        return {dis[0][0],dfs(0,0,n,dis,board)};
    }
};