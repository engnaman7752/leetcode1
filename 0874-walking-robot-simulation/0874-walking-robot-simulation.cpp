class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        set<pair<int,int>>st;
        int n=obstacles.size();
        for(int i=0;i<n;i++){
            st.insert({obstacles[i][0],obstacles[i][1]});
        }
        int ans=0;
        char d='n';
        int m=commands.size();
        for(int i=0;i<m;i++){
            int num=commands[i];
            if(1<=num<=9){
                if(d=='n'){
                    for(int j=1;j<=num;j++){
                        y++;
                        if(st.find({x,y})!=st.end()){
                            y--;
                            break;
                        }
                    }
                }
                  if(d=='s'){
                    for(int j=1;j<=num;j++){
                        y--;
                        if(st.find({x,y})!=st.end()){
                            y++;
                            break;
                        }
                    }
                }
                  if(d=='e'){
                    for(int j=1;j<=num;j++){
                        x++;
                        if(st.find({x,y})!=st.end()){
                            x--;
                            break;
                        }
                    }
                }
                  if(d=='w'){
                    for(int j=1;j<=num;j++){
                        x--;
                        if(st.find({x,y})!=st.end()){
                            x++;
                            break;
                        }
                    }
                }
            }
            if(num==-1){
                if(d=='n'){
                    d='e';
                }
                else if(d=='e'){
                    d='s';
                }
                else if(d=='s'){
                    d='w';
                }
                else if(d=='w'){
                    d='n';
                }
            }
            if(num==-2){
                if(d=='s'){
                    d='e';
                }
               else if(d=='w'){
                    d='s';
                }
                else if(d=='n'){
                    d='w';
                }
                else if(d=='e'){
                    d='n';
                }
            }
            ans=max(ans,x*x+y*y);
        }
        return ans ;
    }
};