class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int num=nums1[i];
            int start=i;
            int end=m-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(nums2[mid]>=num){
                    ans=max(ans,mid-i);
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return max(ans,0);
    }
};