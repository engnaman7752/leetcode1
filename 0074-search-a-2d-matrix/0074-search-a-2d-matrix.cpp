class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n=matrix.size();
      int m=matrix[0].size();
      int start=0;
      int end=n*m-1;
       while(start<=end){
        int mid=start+(end-start)/2;
         int midRow = mid / m;
         int midCol = mid % m;
        if(matrix[midRow][midCol]==target)return true;
        else if(matrix[midRow][midCol]>target){
            end=mid-1;
        }
        else start=mid+1;

       }
       return false;
    }
};