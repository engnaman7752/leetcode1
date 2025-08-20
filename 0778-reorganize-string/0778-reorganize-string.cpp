class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        priority_queue<pair<int,char>>p;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto [ch,count]:mp){
            p.push({count,ch});
        }
        pair<int,char>pre{0,'@'};
        while(!p.empty()){
            auto [count,ch]=p.top();
            count=count-1;
              p.pop();
            ans.push_back(ch);
            if(pre.first>0)p.push(pre);
            pre={count,ch};
        }
        if(ans.size()!=s.size())return "";
        return ans;
    }
};