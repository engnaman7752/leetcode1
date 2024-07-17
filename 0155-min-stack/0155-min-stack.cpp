class MinStack {
public:
vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int>p;
        if(st.empty())
        {
            p.first=val;
            p.second=val;
            
        }
        else
        {
            p.first=val;
            int puranamin=st.back().second;
            p.second=min(val,puranamin);

        }
st.push_back(p);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int>ans=st.back();
        return ans.first;
    }
    
    int getMin() {
         pair<int,int>ans2=st.back();
        return ans2.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */