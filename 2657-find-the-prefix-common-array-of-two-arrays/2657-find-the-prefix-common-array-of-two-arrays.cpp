class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        vector<int>preA(n+1,0);
        vector<int>preB(n+1,0);
        for(int i=0;i<n;i++){
            preA[A[i]]=1;
            preB[B[i]]=1;
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(preA[j]==1 && preB[j]==1){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};