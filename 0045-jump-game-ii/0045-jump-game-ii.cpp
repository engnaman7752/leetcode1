class Solution {
public:
    int jump(vector<int>& arr) {
         int count=0;
        int i=0;
        int n=arr.size();
        if(n==1)return 0;
        while(i<=n-1){
            if(i+arr[i]>=n-1){
                count++;
                return count;
            }
            else{
                int k=i+1;
                for(int j=i+1;j<=i+arr[i];j++){
                    if(j+arr[j]>=k+arr[k]&&arr[j]!=0)k=j;
                }
                i=k;
                count++;
            }
        }
        return -1;
    }
};