class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int no=1;
        for(int i=1;i<=n;i++)
        {ans.push_back(no);
        if(no*10<=n)
       { no=no*10;
        }
        else
        {while(no%10==9||no>=n)
        no=no/10;
        no=no+1;}

        }

return ans;           
        
    }
};