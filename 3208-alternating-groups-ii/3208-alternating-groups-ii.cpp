class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int left=0; int right=1;int ans=0;
        while(right<n){
            if(colors[right]==colors[right-1])left=right;
            if(right-left+1==k){
                ans++;
                left++;
            }
            right++;
            if(right==n&&colors[n-1]!=colors[0]){
                bool flag=true;
                for(int i=1;i<k-(n-left);i++){
                    if(colors[i]==colors[i-1]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    int cnt=1;
                    for(int i=k-(n-left);i<k-1;i++){
                        if(colors[i]==colors[i-1])break;
                        cnt++;
                    }
                    ans+=cnt;
                }
                break;
            }
        }
        return ans;
    }
};