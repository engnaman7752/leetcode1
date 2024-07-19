class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        vector<int>realans;
        for(int i=0;i<n;i++)
        {
            int minno=INT_MAX;
            for(int j=0;j<m;j++)
            {
                minno=min(matrix[i][j],minno);
            
            }
            ans.push_back(minno);
        }
         for(int i=0;i<m;i++)
        {
            int maxno=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(maxno<matrix[j][i])
                maxno=matrix[j][i];
            
            }
            
            ans.push_back(maxno);
        }
      if (ans.size()==2)
      return ans;
        
        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]==ans[i+1])
            realans.push_back(ans[i]);
            
        }
        return realans;
    }
};