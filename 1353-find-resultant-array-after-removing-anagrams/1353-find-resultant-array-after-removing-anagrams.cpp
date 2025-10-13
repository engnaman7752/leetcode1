class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>temp=words;
        vector<string>ans;
         ans.push_back(temp[0]);
         sort(words[0].begin(),words[0].end());
       for(int i=1;i<words.size();i++){
        sort(words[i].begin(),words[i].end());
        if(words[i]!=words[i-1])ans.push_back(temp[i]);
       } 
       return ans;

    }
};