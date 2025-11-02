class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // if num == 0 simply clear the array since multiplying with 0 is 0
        if(num == 0) {
            prefix.clear();
        }
        else{
            // if array is empty just add first num
            if(prefix.empty()) prefix.push_back(num);
            // else multiply it with the lasr val
            else prefix.push_back(prefix.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k > prefix.size()) return 0;
        if(k == prefix.size()) return prefix.back();

        return prefix.back()/ prefix[prefix.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */