class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>arr(10,0);
        vector<int>ans;
        for(int i=0;i<digits.size();i++)
        {
            arr[digits[i]]++;
        }
        for(int i=100;i<999;i=i+2)
        {vector<int>num(10,0);
            int n=i;
            while(n>0)
            {
                num[n%10]++;
                n=n/10;}
                bool flag=true;
                for(int i=0;i<10;i++)
                {
                    if(arr[i]<num[i])
                    {flag=false;
                    break;}
                }
                if(flag)
                ans.push_back(i);
            }
        return ans;
    }
};