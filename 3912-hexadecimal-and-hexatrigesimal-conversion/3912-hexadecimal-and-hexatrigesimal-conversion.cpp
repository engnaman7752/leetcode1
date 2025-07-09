class Solution {
public:
    string concatHex36(int n) {
        vector<char>v(36);
        char a='A';
        for(int i=0;i<36;i++)
        {
            if(i<=9)
            {char x='0'+i;
            v[i]=x;}
            else
            {v[i]=a;
            a++;}
        }
        int tri=n*n*n;
        int hex=n*n;
        string ans1;
        while(hex>=16)
        {
            ans1.push_back(v[hex%16]);
            hex=hex/16;
        }
        if(hex>0)ans1.push_back(v[hex]);
        reverse(ans1.begin(),ans1.end());
         string ans2;
        while(tri>=36)
        {
            ans2.push_back(v[tri%36]);
            tri=tri/36;
        }
        if(tri>0)ans2.push_back(v[tri]);
        reverse(ans2.begin(),ans2.end());
        return ans1+ans2;
    }
};