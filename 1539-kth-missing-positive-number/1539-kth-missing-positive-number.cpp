class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0;
        int end=arr.size()-1;
        int index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]-(mid+1)<k){
                index=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(index==-1)return k;
        return arr[index]+k-(arr[index]-(index+1));
    }
};