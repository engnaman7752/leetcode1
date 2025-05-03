class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        for(int i=0;i<=6;i++)
        {   bool check=true;
            int x=i;
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(tops[j]!=x&&bottoms[j]!=x)
               { check=false;
                break;}
                if(tops[j]!=x&&bottoms[j]==x)
                count++;
            }
            if(check&&ans>count)
            ans=count;
        }
         for(int i=0;i<=6;i++)
        {   bool check=true;
            int x=i;
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(tops[j]!=x&&bottoms[j]!=x)
               { check=false;
                break;}
                if(tops[j]==x&&bottoms[j]!=x)
                count++;
            }
            if(check&&ans>count)
            ans=count;}

        if(ans==INT_MAX)
        return -1;
    return ans;
        
    }
};