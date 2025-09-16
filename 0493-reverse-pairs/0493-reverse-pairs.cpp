class Solution {
public:
    int reversePairs(vector<int>& arr) {
         int n=arr.size();
        int start=0;
        int end=n-1;
       return solve(arr,start,end);
    }
    int solve(vector<int>&arr,int start,int end){
        if(start>=end)return 0;
        int mid=start+(end-start)/2;
        int count=0;
        count+=solve(arr,start,mid);
        count+=solve(arr,mid+1,end);
        count+=merge(arr,start,end,mid);
        return count;
        
    }
    int merge(vector<int>&arr,int start,int end,int mid){
        vector<int>temp;
        int j=mid+1;
        int c=0;
        
        for (int i = start; i <= mid; i++) {
    while (j <= end && (long long)arr[i] > 2LL * arr[j]) j++;
    c += (j - (mid + 1));
}
int i=start;
j=mid+1;
        for(;i<=mid&&j<=end;){
            if(arr[i]>arr[j]){
                temp.push_back(arr[j]);
                j++;
            }
            else{
                temp.push_back(arr[i++]);
            }
        }
       while(i<=mid)temp.push_back(arr[i++]);
       while(j<=end)temp.push_back(arr[j++]);
       int p=0;
       for(int k=start;k<=end;k++){
           arr[k]=temp[p++];
       }
        return c;
    }
};