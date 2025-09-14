class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s=m;
        int i=0;
        int j=0;
        while(j<m+n&&i<n){
            if(nums1[j]>nums2[i]){
                int k=j;
                int pre=nums1[k];
                while(k+1<n+m){
                    int fow=nums1[k+1];
                    nums1[k+1]=pre;
                    pre=fow;
                    k++;}
                nums1[j]=nums2[i];
                i++;
            }
            else
            j++;
            
        }
        while(i<n){
            nums1[m+i]=nums2[i];
            i++;
            j++;
        }
        
    }
};