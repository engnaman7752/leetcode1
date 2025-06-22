class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i=i+k)
        {
            if(i+k>n)
            {
                string temp;
                for(int j=i;j<n;j++)
                temp.push_back(s[j]);
                int p=temp.size();
                while(p<k)
                {temp.push_back(fill);
                p++;}
                ans.push_back(temp);

            }
            else
            ans.push_back(s.substr(i,k));


        }
        return ans;
        
    }
};