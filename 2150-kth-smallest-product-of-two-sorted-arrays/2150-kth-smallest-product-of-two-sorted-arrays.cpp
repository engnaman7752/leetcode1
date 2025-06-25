class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left=-1e10;
        long long right=1e10;
        long long n1=nums1.size();
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            long long count=0;
            for(int i=0;i<n1;i++)
            {count+=solve(mid,nums1[i],nums2);}
            if(count<k)
            left=mid+1;
            else
            right=mid-1;
            cout<<count<<endl;

        }
        return left;
    }
long long solve(long long v,int x1,vector<int>&nums2)
{
    int n2=nums2.size();
    int left=0;
    int right=n2-1;
     while (left <= right) {
           int mid = left + (right - left) / 2;
           long long prod=(long long)nums2[mid] * x1;
            if (x1 >= 0 && prod <= v || x1 < 0 && prod> v) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

    if(x1>=0)
    return left;
    else
    return n2-left;
}
};