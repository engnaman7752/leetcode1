class Solution {
public:
    bool possible(int mid,vector<int>& piles, int h){
        int cnt=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            cnt+=piles[i]/mid;
            if(piles[i]%mid!=0){
                cnt++;
            }
            if(cnt>h)return 0;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,piles,h)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};