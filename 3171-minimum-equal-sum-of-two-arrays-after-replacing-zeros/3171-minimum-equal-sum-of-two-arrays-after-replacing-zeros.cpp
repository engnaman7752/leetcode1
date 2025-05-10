class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        long long cn1=count(nums1.begin(),nums1.end(),0);
        long long cn2=count(nums2.begin(),nums2.end(),0);
        for(int i=0;i<nums1.size();i++)
        sum1=sum1+nums1[i];
        for(int i=0;i<nums2.size();i++)
        sum2=sum2+nums2[i];
        if(cn1!=0&&cn2!=0)
        return max(sum1+cn1,sum2+cn2);
        if(cn1==0&&cn2==0&&sum1==sum2)
        return sum1;
        if(cn1+sum1==cn2+sum2)
        return sum1+cn1;
        if(cn1>0&&cn2==0&&sum2>sum1+cn1)
        return sum2;
        if(cn2>0&&cn1==0&&sum1>sum2+cn2)
        return sum1;
        return -1;
    }
};