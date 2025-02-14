class ProductOfNumbers {
public:
vector<long long>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        for(int i=0;i<ans.size();i++)
        {
           ans[i]= long (num*ans[i]);
        }
        ans.push_back(num);
        
    }
    
    int getProduct(int k) {
        return ans[ans.size()-k];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */