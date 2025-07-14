class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0;
        for(int i=0,j=0;j<players.size()&&i<trainers.size();i++){
            if(players[j]<=trainers[i]){
                ans++;
                j++;
            }
        }
        return ans;
    }
};