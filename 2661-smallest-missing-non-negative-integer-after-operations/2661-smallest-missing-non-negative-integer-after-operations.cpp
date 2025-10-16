class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        vector<bool>v(n+1,false);
        map<int,int>mp;
        for(int i=0;i<n;i++){
           int a= (abs(nums[i]) % value);
           if(nums[i]<0&&a!=0)a=value-a;
           cout<<a<<endl;
            if(mp.find(a)==mp.end()){
            mp[a]=a;
            if(a<=n)
            v[a]=true;}
            else{
                if(mp[a]+value<=n)
                v[mp[a]+value]=true;
                mp[a]=mp[a]+value;

        }
        }
        for(int i=0;i<=n;i++){
            if(v[i]==false)return i;
        }
        return n;
    }
};