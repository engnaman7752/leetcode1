class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st;
        for(int i=0;i<wordList.size();i++)
        st.insert(wordList[i]);
        st.erase(beginWord);
        queue<string>q;
        q.push(beginWord);
        int count=1;
        while(!q.empty())
        {
            count++;
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                string s=q.front();
                q.pop();
                for(int i=0;i<s.size();i++)
                { string change=s;
                    for(char letter='a';letter<='z';letter++)
                    {
                        change[i]=letter;
                        if(st.find(change)!=st.end())
                        {q.push(change);
                        st.erase(change);
                        if(change==endWord)
                        return count;}
                    }
                }
            }
        }
        return 0;
    }
};