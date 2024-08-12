class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        
        int k=0;
        for(int i=1;i<=n&&k<target.size();i++)
        {
           ans.push_back("Push");
            if(i!=target[k])
           { ans.push_back("Pop");
           
            }
            else
            {k++;}
        }
        return ans;


        
    }
};