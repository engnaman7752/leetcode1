class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      int ans=0;
      int n=strs.size();int m=strs[0].size();
      for(int i=0;i<m;i++){
        bool flag=false;
        for(int j=0;j<n-1;j++){
            if(strs[j][i]>strs[j+1][i]){
                flag=true;
                break;
            }
        }
         if(flag){
                ans++;
            }
      } 
      return ans; 
    }
};