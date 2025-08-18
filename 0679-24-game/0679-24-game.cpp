class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        vector<double>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=cards[i];
        }
        return dfs(nums);
        
    }
    bool dfs(vector<double>nums){
        int n=nums.size();
        if(nums.size()==1){
            if(abs(nums[0]-24)<=1e-5)return true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                vector<double>next;
                for(int k=0;k<n;k++){
                    if(i!=k&&j!=k)next.push_back(nums[k]);
                }
                vector<double>op=compute(nums[i],nums[j]);
                for(int l=0;l<op.size();l++)
               { next.push_back(op[l]);
                if(dfs(next))return true;
                next.pop_back();}
            }
        }
        return false;
    }
    vector<double>compute(double a,double b){
        vector<double>res{a+b,a-b,b-a,a*b};
        if(a)res.push_back(b/a);
        if(b)res.push_back(a/b);
        return res;
    }
};