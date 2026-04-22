class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        vector<string>ans;
        int m=queries[0].size();
        for(auto s:queries){
            for(auto k:dictionary){
                int cnt=0;
                for(int j=0;j<m;j++){
                    if(s[j]!=k[j])cnt++;
                }
                if(cnt<=2){ans.push_back(s);break;}
            }
            
        }
          return ans; 
    }
};