class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        unordered_set<int> s;
        unordered_set<int>pre;
      
        for (int i = 0; i < nums.size(); i++) {
            int orr = nums[i];
            unordered_set<int>curr;
            curr.insert(orr);
           for(auto it:pre){
            curr.insert(orr|it);
           }
           pre=curr;
           s.insert(pre.begin(),pre.end());
        }
        return s.size();
    }
};
