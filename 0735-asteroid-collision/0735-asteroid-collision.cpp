class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n=asteroids.size();
        stack<int>st;
        st.push(asteroids[0]);
       for(int i=1;i<n;i++)
       {
        if(!st.empty()&&((st.top()>=0&&asteroids[i]>0)||(st.top()<0)))
        st.push(asteroids[i]);
        else
        {bool flag=true;
            while(!st.empty())
            {if(!st.empty()&&((st.top()>=0&&asteroids[i]>0)||(st.top()<0)))
        {st.push(asteroids[i]);break;}
                if(abs(st.top())>abs(asteroids[i]))
                break;
                else if(abs(st.top())==abs(asteroids[i])&&(st.top()*asteroids[i])<0)
                {st.pop();flag=false;
                break;}
                else
                st.pop();
            }
            if(st.empty()&&flag)
            st.push(asteroids[i]);
        }
       }
       while(!st.empty())
      { ans.push_back(st.top());
       st.pop();}
       reverse (ans.begin(),ans.end());
       return ans;
    }
};