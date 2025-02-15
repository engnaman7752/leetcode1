class Solution {
    private:
    bool check(int num,int target)
    {
        if(num==target)return true;
        if(target<0||num<target)return false;
        return check(num/10,target-num%10)||
        check(num/100,target-num%100)||
        check(num/1000,target-num%1000);
        
    }
public:
  int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {int sqr=i*i;
            if(check(sqr,i))
        ans=ans+sqr;

        }
        return ans;
        
        
    }
};