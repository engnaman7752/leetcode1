class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=2*n;
        cout<<ans<<endl;
        int k=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        for(int i=0;i<k;){
            vector<int>temp(10,1);
            int j=i;
            while(j<k && reservedSeats[i][0]==reservedSeats[j][0]){
                temp[reservedSeats[j][1]-1]=0;
                j++;
            }
            i=j;
            int cnt=0;
            if(temp[1]==0 || temp[2]==0 || temp[3]==0 ||temp[4]==0)cnt++;
            if(temp[3]==0 || temp[4]==0 ||temp[5]==0 || temp[6]==0)cnt++;
            if(temp[5]==0 || temp[6]==0 ||temp[7]==0 || temp[8]==0)cnt++;
            if(cnt==3)ans-=2;
            else if(cnt!=0)ans-=1;
            cout<<ans<<endl;

        }
        return ans;
    }
};