class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first;
        string second;
        if(x>y){
            first="ab";
             second="ba";}
            else{
                first="ba";
                second="ab";

            }
            string remain=change(s,first);
            int count=((s.size()-remain.size())/2)*max(x,y);
            string remain2=change(remain,second);
            count+=((remain.size()-remain2.size())/2)*min(x,y);

            return count;
    }
    string change(string orignal,string word){
        char x=word[0];
        char y=word[1];
        stack<char>st;
        for(int i=0;i<orignal.size();i++){
             if(!st.empty()&&st.top()==x&&orignal[i]==y)
              st.pop();
              else
              st.push(orignal[i]);
        }
        string send;
        while(!st.empty()){
            send.push_back(st.top());
            st.pop();
        }
        reverse(send.begin(), send.end());
        return send;
        
    }
};