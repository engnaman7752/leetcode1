class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0;
        int u=0;
        int n=moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='L')l++;
            if(moves[i]=='R')l--;
            if(moves[i]=='U')u++;
            if(moves[i]=='D')u--;
        }
        return l==0 && u==0 ;
    }
};