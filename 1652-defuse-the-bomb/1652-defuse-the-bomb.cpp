class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();vector<int>a(n,0);int sum=0;
        if(k==0){
            return a;
        }
        int left=1;int right=k;
        if(k<0){
            left=n-abs(k);
            right=n-1;
        }
        for(int i=left;i<=right;i++)sum+=code[i];
        for(int i=0;i<n;i++){
            a[i]=sum;
            sum-=code[left%n];
            left++;
            right++;
            sum+=code[right%n];
        }
        return a;
    }
};