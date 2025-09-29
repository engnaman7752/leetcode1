class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<long long>ten(10);
        ten[0]=1;
        for(int i=1;i<10;i++)ten[i]=ten[i-1]*10;
        int start=0;
        vector<int>ans;
        while(n>0){
            if(n%10!=0)
            ans.push_back(n%10*ten[start]);
            n=n/10;
            start++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};