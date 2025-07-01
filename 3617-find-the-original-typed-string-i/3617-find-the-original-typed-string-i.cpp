class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        for(int i=0;i<word.size();)
        {int count=0;
            for(int j=i;j<word.size();j++)
        {
            if(word[i]==word[j])
            count++;
            else
            break;
        }
        ans=ans+count-1;
        i=i+count;
            
        }
        

        return ans;
    }
};