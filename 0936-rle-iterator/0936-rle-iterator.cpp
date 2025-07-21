class RLEIterator {
    map<long long,long long >mp;
    long long index=0;
public:
    RLEIterator(vector<int>& encoding) {
        long long pre=0;
        for(int i=0;i<encoding.size();i=i+2){
            if(encoding[i]!=0)
           { mp[encoding[i]+pre]=encoding[i+1];
            pre+=encoding[i];}
        }
        
    }
    
    int next(int n) {
      long long x=index+(long long)n;
      index=index+n;
        for(auto it:mp){
            if(it.first>=x){
                return it.second;}
        }
        return -1;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */