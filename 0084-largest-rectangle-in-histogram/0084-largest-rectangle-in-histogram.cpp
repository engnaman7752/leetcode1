class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
         stack<int>st2;
        vector<int>left(n);
        vector<int>right(n);
        
        st.push(-1);
        for (int i = 0; i < n; i++)
    {
        int curr = heights[i];
        while (st.top() >=curr)
        {
            st.pop();
        }
        left[i]=st.top();
        st.push(curr);
    }

       
        st2.push(-1);
        for(int i=n-1;i>=0;i--)
        {
 while(heights[i]<=st2.top())
            st2.pop();
            right[i]=st2.top();
            st2.push(heights[i]);
        }
        int area=0;
        
        for(int i=0;i<n;i++)
        {int sum=0;
            if(left[i]==-1)
            {sum=sum+(i*heights[i]);}
            else
           { for(int j=i-1;heights[j]!=left[i];j--)
            sum=sum+heights[i];}
            if(right[i]==-1)
            sum=sum+(heights[i]*(n-1-i));
            else
            {for(int j=i+1;heights[j]!=right[i];j++)
            sum=sum+heights[i];

            }
            sum=sum+heights[i];
            area=max(area,sum);


        }

       
        return area;
    }
};