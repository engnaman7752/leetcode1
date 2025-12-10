class Solution {
public:
   const int MOD = 1e9 + 7;

int fac(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return (1LL * n * fac(n - 1)) % MOD;
}

int countPermutations(vector<int>& complexity) {
    int n = complexity.size();
    if(complexity[n-1]<=complexity[0])
        return 0;
        for(int i=1;i<n-1;i++)
            {if(complexity[i]<=complexity[0]||(complexity[i]==complexity[i+1]&&complexity[i]==complexity[i-1]))
                return 0;}
        
    
     return fac(n - 1);   
}
};