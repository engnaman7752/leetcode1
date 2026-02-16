class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int>pre(n,0);vector<int>post(n,0);
        post[0]=customers[0];
        if(grumpy[0]==0)pre[0]=post[0];
        for(int i=1;i<n;i++){
            post[i]=post[i-1]+customers[i];
            if(grumpy[i]==0)pre[i]=pre[i-1]+customers[i];
            else pre[i]=pre[i-1];
        }
        int newAdd=0;int left=0;
        for(int right=0;right<n;right++){
            if(right-left+1==minutes){
                int pr=pre[right];int po=post[right];
                if(left!=0)
                {pr=pre[right]-pre[left-1];
                po=post[right]-post[left-1];}
                newAdd=max(newAdd,po-pr);
                left++;
            }
        }
        return pre[n-1]+newAdd;
    }
};