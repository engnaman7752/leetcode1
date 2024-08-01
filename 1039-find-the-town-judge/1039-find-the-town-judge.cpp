class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        stack<int>st;
        for(int i=1;i<=n;i++)
        {
            st.push(i);
        }
        while(true)
        {bool flag=true;
            for(int i=0;i<trust.size();i++)
           { 
            if((!st.empty())&&st.top()==trust[i][0])
            {
                st.pop();
                flag =false;;
            }
           

            }
             if(flag)
            break;

           
        }
        if(st.size()==0)
        return -1;
        int x=st.top();
        int count=0;
        for(int i=0;i<trust.size();i++)
        {
            if(trust[i][1]==x)
            count++;
        }
        if(count==n-1)
        return x;
        else
        return -1;

    }
};