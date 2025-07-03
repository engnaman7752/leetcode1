class Solution {
    char solve(string &ans,int k){
        if(ans.size()>=k)
        return ans[k-1];
        int x=ans.size();
        for(int i=0;i<x;i++){
            if(ans[i]!='z')
            ans.push_back(ans[i]+1);
            else
            ans.push_back('a');
        }
        return solve(ans,k);
       
    }
public:
    char kthCharacter(int k) {
        string ans="a";
        return solve(ans,k);
        
    }
};