class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        int n=s.size();
        if(s[n-1]=='1')return false;
        q.push(0);
        int last=0;
        while(!q.empty()){
            int i=q.front();
         
            q.pop();
            if(i==n-1)return true;
            for(int j=max(i+minJump,last+1);j<=min(i + maxJump, n- 1);j++){
                if( s[j]=='0')q.push(j);
            }
            last=max(last,min(i + maxJump, n- 1));
        }
        return false;
    }
};