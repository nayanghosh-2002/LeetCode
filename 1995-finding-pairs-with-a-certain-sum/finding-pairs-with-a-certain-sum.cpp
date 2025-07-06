class FindSumPairs {
public:
    unordered_map<long long,int>m;
    unordered_map<int,int>m1;
    vector<int>nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        nums = nums2;
        for(auto val: nums1)
        {
            m1[val]++;
        }

        for(auto val: nums2)
        {
            m[val]++;
        }
    }
    
    void add(int index, int val) 
    {
        int oldVal = nums[index];
        m[oldVal]--;
        if(m[oldVal]==0)
        {
            m.erase(oldVal);
        }
        int newVal = oldVal+val;
        nums[index] = newVal;
        m[newVal]++;
    }
    
    int count(int tot) 
    {
        int c = 0;
        for(auto it: m1)
        {
            int val = tot-it.first;
            if(m.find(val)!=m.end())
            {
                c+=(it.second*m[val]);
            }
        }

        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */