class ProductOfNumbers {
public:

    vector<long long>v;
    int idx0 = -1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0) idx0 = v.size(),v.push_back(1);
        else if(v.size()==0)v.push_back(num);
        else v.push_back(v.back()*num);
        // for(int i = 0;i<v.size();i++) cout<<v[i]<<" ";
        // cout<<endl;
        
    }
    
    int getProduct(int k) {
        int l = v.size()-k;
        if(idx0>=l) return 0;
        if(l>0) return v[v.size()-1]/v[l-1];
        return v[v.size()-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */