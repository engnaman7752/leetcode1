class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(int i=0;i<words.size();i++)
        {   
            mp[words[i]]++;
        }
        int count=0;
        bool flag=false;
         for(int i=0;i<words.size();i++)
        {   
           string rev(words[i].rbegin(), words[i].rend()); 
            if(rev==words[i]&&mp[words[i]]%2)
            flag=true;
            if(mp[rev]>0&&mp[words[i]]>0)
            {if(rev==words[i]&&mp[words[i]]==1)continue;
                mp[rev]--;
                mp[words[i]]--;
                count++;
            }
        }
       int ans=4*count;
        if(flag)
        ans+=2;
        return ans;
        
       
    }
};