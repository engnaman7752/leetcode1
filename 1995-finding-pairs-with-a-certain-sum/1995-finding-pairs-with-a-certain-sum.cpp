class FindSumPairs {
    map<int,int>mp;
    vector<int>arr1;
    vector<int>arr2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
        for(int i=0;i<nums2.size();i++)
        mp[nums2[i]]++;
    }
    
    void add(int index, int val) {
        arr2[index]+=val;
        mp[arr2[index]]++;
        mp[arr2[index]-val]--;
        
    }
    
    int count(int tot) {
        int count=0;
        for(int i=0;i<arr1.size();i++)
        {count=count+mp[tot-arr1[i]];

        }
        return count;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */