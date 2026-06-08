class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int na=nums1.size();
        int nb=nums2.size();
        int n=na+nb;
        if(n%2){
            return solve(nums1,nums2,0,na-1,0,nb-1,n/2);
        }
        else{
            return 1.0*(solve(nums1,nums2,0,na-1,0,nb-1,n/2)+solve(nums1,nums2,0,na-1,0,nb-1,n/2-1))/2;
        }
    }
    int solve(vector<int>& nums1, vector<int>& nums2,int a_start,int a_end,int b_start,int b_end,int k){
        if(a_start>a_end){
            return nums2[k-a_start];
        }
        if(b_start>b_end){
            return nums1[k-b_start];
        }
        int idx1=a_start+(a_end-a_start)/2;
        int idx2=b_start+(b_end-b_start)/2;
        if(idx1+idx2<k){
            if(nums1[idx1]<nums2[idx2]){
                return solve(nums1,nums2,idx1+1,a_end,b_start,b_end,k);
            }
            else{
                return solve(nums1,nums2,a_start,a_end,idx2+1,b_end,k);
            }
        }
        else{
            if(nums1[idx1]<nums2[idx2]){
                return solve(nums1,nums2,a_start,a_end,b_start,idx2-1,k);
            }
            else{
                return solve(nums1,nums2,a_start,idx1-1,b_start,b_end,k);
            }
        }
        return -1;
    }
};