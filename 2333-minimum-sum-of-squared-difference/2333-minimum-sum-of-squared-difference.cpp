class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>a(1e5+1,0);
        int n=nums1.size();
        for(int i=0;i<n;i++){
            a[abs(nums2[i]-nums1[i])]++;
        }
        int total=k1+k2;
        int i=a.size()-1;
        while(total>0 && i>0){
            if(a[i]==0){
                i--;
                continue;
            }
            if(total>=a[i]){
                a[i-1]+=a[i];
                total-=a[i];
                a[i]=0;
            }
            else{
                a[i-1]+=total;
                a[i]-=total;
                total=0;
            }
            i--;
        }
        long long sum=0;
        for(int k=1;k<a.size();k++){
            if(a[k]>0)
            sum=sum+(1LL*a[k]*k*k);
        }
        return sum;
    }
};