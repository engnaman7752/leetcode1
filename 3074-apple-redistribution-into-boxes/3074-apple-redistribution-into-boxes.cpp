class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int ans=0;
        for(int i:capacity){
            sum-=i;
            ans++;
            if(sum<=0)return ans;
        }
        return 0;
    }
};