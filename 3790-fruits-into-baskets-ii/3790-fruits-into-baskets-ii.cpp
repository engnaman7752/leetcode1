class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
      for(int i=0;i<fruits.size();i++){
        int add=1;
        for(int j=0;j<baskets.size();j++){
            if(fruits[i]<=baskets[j]){
                add=0;
                baskets[j]=0;
                break;
            }

        }
        ans=ans+add;
      }
      return ans;
    }
};