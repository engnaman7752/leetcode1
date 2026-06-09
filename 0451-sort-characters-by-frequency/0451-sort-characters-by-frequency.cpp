class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto [c,num]:mp){
            pq.push({num,c});
        }
        string ans="";
        while(!pq.empty()){
            auto [num,ch]=pq.top();
            pq.pop();
            while(num){
                ans+=ch;
                num--;
            }
        }
        return ans;
    }
};