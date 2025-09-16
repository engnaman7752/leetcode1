class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
       vector<int>r;
       solve(0,candidates,target,ans,r);
       return ans; 
    }
    void solve(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>r){
        int n=candidates.size();
        if(target==0){
            ans.push_back(r);
            return ;
        }
        if(index==n||target<0)return;
        r.push_back(candidates[index]);
         solve(index,candidates,target-candidates[index],ans,r); 
         r.pop_back();
         solve(index+1,candidates,target,ans,r); 
         
    }
};