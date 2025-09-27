class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int>prex(n);
        vector<int>prey(n);
        set<pair<int,int>> last; 

        for (int i = 0; i <n; i++) {
            int x = 0, y = 0;
          char c=s[i];
                if (c == 'U') y++;
                else if (c == 'D') y--;
                else if (c == 'L') x--;
                else if (c == 'R') x++;
         
            if(i==0){prex[i]=x;prey[i]=y;}
            else {
                prex[i]=x+prex[i-1];
                prey[i]=y+prey[i-1];
            }
        }
last.insert({(prex[n-1]-prex[k-1]),(prey[n-1]-prey[k-1])});
     int left=0;
     int right=k;
     while(right<n){
        last.insert({(prex[n-1]-prex[right]+prex[left]),(prey[n-1]-prey[right]+prey[left])});
        right++;
        left++;
     }
     return last.size();
    }
};
