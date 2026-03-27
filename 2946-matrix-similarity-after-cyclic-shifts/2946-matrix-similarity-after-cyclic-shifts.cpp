class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>temp=mat;int n=mat.size();int m=mat[0].size();
        while(k--){
            for(int i=0;i<n;i++){
                if(i%2==0){
                    reverse(temp[i].begin(),temp[i].end());
                    reverse(temp[i].begin(),temp[i].begin()+m-1);
                }
                else{
                    reverse(temp[i].begin(),temp[i].end());
                    reverse(temp[i].begin()+1,temp[i].end());
                }
            }
        }
        return temp==mat;
    }
};