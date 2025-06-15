class Solution {
    private:
    void solve(int line,vector<string>a,vector<vector<string>>& ans,int n)
    {
        if(line>=n)
       { ans.push_back(a);
        return;}
        int count=0;
        for(int i=0;i<a[line].size();i++)
        {if(a[line][i]=='#')
        break;
        else
        count++;}
        if(count==n)
        return;
        for(int i=0;i<a[line].size();i++)
        {vector<string>temp=a;
            if(a[line][i]=='#')
           {
            int f=0;
            while(f<n)
            {a[line][f]='.';
            f++;}
            a[line][i]='Q';
            int j=line+1;
            while(j<n)
            {a[j][i]='.';
            j++;}
            int k=line+1;
            int l=i+1;
            while(k<n&&l<n)
            {
                a[k][l]='.';
                k++;
                l++;
            }
            k=line+1;
            l=i-1;
             while(l>=0&&k<n)
            {
                a[k][l]='.';
                k++;
                l--;
            }
            solve(line+1,a,ans,n);
            a=temp;


           }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> a(n, string(n, '#'));
        solve(0,a,ans,n);
        return ans;
}
    
};