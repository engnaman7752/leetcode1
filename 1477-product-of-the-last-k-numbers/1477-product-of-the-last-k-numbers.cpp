class ProductOfNumbers {
public:
vector<long long>ans{1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
       if(num==0)
       {ans.clear();
       ans.push_back(1);}
       else
       ans.push_back(num*ans[ans.size()-1]);
        
    }
    
    int getProduct(int k) {
       if(ans.size()<=k) return 0;
       else
       return ans[ans.size()-1]/ans[ans.size() - k - 1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */