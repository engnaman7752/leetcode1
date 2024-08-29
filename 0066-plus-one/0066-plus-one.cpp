class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
   bool flag=true;
        if(digits[n-1]==9)
        {
            int i=n-1;
            while(digits[i]==9&&i>=0)
            {if(i==0)
               {digits[i]=0;
                    digits.push_back(1);
                reverse (digits.begin(),digits.end());
                flag=false;
                break;}
                digits[i]=0;
                i--;
              
               
            }

            if(i>=0&&flag)
           digits[i]++;
        }
        else
        digits[n-1]++;
        return digits;
    }
};