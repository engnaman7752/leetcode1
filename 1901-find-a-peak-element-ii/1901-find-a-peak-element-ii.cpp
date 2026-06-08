class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int start=0;
        int end=m-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int index=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[index][mid])index=i;
            }
            if(mid==0){
                if(mat[index][mid]>mat[index][mid+1])return {index,mid};
                else{
                    start=mid+1;
                }
                continue;
            }
            if(mid==m-1){
                if(mat[index][mid]>mat[index][mid-1])return {index,mid};
                else{
                    end=mid-1;
                }
                continue;
            }
            if(mat[index][mid]>mat[index][mid-1] && mat[index][mid]>mat[index][mid+1])return {index,mid};
            else if(mat[index][mid]<mat[index][mid-1])end=mid-1;
            else start=mid+1;
        }
        return {};
    }
};