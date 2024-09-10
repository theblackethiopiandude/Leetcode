int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(const auto& account: accounts)
            maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
        
        return maxWealth;
  }

int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i = 0, sum = 0; i < accounts.size(); i++, sum = 0){
            for(int j = 0; j < accounts[i].size(); j++)
                sum += accounts[i][j];
            if(sum > max)
                max = sum;
        }
        return max;
    }
