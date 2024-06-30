class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for(int i = 0; i < products.size(); i++)
            umap[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill = 0;
        for(int i = 0; i < product.size(); i++)
            bill += umap[product[i]] * amount[i];

        return (++k % n)? bill : (bill * (100 - discount)) / 100 ;
    }
private:
    unordered_map<int, int> umap;
    int discount;
    int n, k = 0;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
