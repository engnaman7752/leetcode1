class Solution {
public:
string DecimalToBinaryString(int a,int k)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < k; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    return binary;
}
    bool hasAllCodes(string s, int k) {
        int l=1<<(k);
        vector<bool>mp(l,false);
        int left=0;set<string>t;int n=s.size();
        for(int right=0;right<n;right++){
            if(right-left+1==k){
                string t=s.substr(left,k);
                mp[stoi(t,nullptr,2)]=true;
                left++;
            }
        }
        for(int i=0;i<l;i++){
            if(mp[i]==false)return false;
        }
        return true;
    }
};