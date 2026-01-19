class Solution {
public:
bool isPossible(int i,int j,int mid,vector<vector<int>>&row,int threshold){
    bool flag=true;
    int sum=0;
    for(int l=i;l<=i+mid;l++){
        sum+= row[l][j + mid] - (j > 0 ? row[l][j - 1] : 0);
        if(sum>threshold){
            flag=false;
            break;
        }
    }
    return flag;
}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
       vector<vector<int>>row(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=mat[i][j];
            row[i][j]=sum;
        }
       }
       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int start=0;
            int end=min(n-i,m-j);
            int mid;
            while(start<end){
                mid=start+(end-start)/2;
                if(isPossible(i,j,mid,row,threshold)){
                    start=mid+1;
                    ans=max(mid+1,ans);
                }
                else{
                    end=mid;
                }

            }
        }
       }  
       return ans;
    }
};