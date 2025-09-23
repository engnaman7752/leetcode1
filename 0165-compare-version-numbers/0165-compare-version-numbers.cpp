class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;int j=0;
        int n=version1.size();int m=version2.size();
        while(i<n||j<m){
            string temp1=""; string temp2="";
            while(i<n&&version1[i]!='.'){
                temp1.push_back(version1[i]);
                i++;
            }

            while(j<m&&version2[j]!='.'){
                temp2.push_back(version2[j]);
                j++;
            }
          int x1 = temp1.empty() ? 0 : stoi(temp1);
        int x2 = temp2.empty() ? 0 : stoi(temp2);
          if(x1>x2)return 1;
          else if(x2>x1)return -1;
          i++;
          j++;
        }
        return 0;
    }
};