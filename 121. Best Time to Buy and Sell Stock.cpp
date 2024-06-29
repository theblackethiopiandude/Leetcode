int maxProfit(vector<int>& prices) {
        int mi = numeric_limits<int>::max();
        int ma = 0;
        for(int i = 0; i < prices.size(); i++){
            mi = min(mi, prices[i]);
            int profit = prices[i] - mi;
            if(profit > 0)
                ma = max(ma, profit);
        }
        

        return ma;
    }
