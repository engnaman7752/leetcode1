class Solution {
public:
    bool possible(int mid,vector<vector<int>>& tasks){
        for(auto e:tasks){
            if(e[1]>mid)return false;
            mid-=e[0];
        }
        if(mid<0)return false;
        return true;
    }
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[1]-a[0]>b[1]-b[0];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int start=0;
        int end=0;
        int a=0;int b=0;
        sort(tasks.begin(),tasks.end(),cmp);
        for(auto e:tasks){
            a+=e[0];
            b+=e[1];
        }
        end=max(a,b);
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,tasks)){
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