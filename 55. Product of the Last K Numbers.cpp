class ProductOfNumbers {
private:
    vector<int> prefixProducts;

public:
    ProductOfNumbers() {
        prefixProducts = {1}; // Initialize with 1 to handle multiplication
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProducts = {1}; // Reset on zero
        } else {
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProducts.size();
        if (k >= size) return 0; // If zero was encountered, return 0
        return prefixProducts.back() / prefixProducts[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
