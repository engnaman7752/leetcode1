class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,int>mp;int n=positions.size();
        vector<tuple<int,int,char>>robo;
        for(int i=0;i<n;i++){
            robo.push_back({positions[i],healths[i],directions[i]});
        }
        sort(robo.begin(),robo.end());
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int cnt=0;bool flag=true;
            auto [p,h,d]=robo[i];
            if(d=='R')st.push({h,p});
            else{
                while(!st.empty()){
                    auto [t,po]=st.top();
                    st.pop();
                    if(h-cnt<t){
                        st.push({t-1,po});
                        flag=false;
                        break;
                    }
                    else if(h-cnt==t){
                        flag=false;
                        break;
                    }
                    cnt++;
                }
                if(st.empty() && flag)mp[p]=h-cnt;
            }
        }
        while(!st.empty()){
            auto [t,po]=st.top();
            st.pop();
            mp[po]=t;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.find(positions[i])!=mp.end()){
                ans.push_back(mp[positions[i]]);
            }
        }
        return ans;
    }
};