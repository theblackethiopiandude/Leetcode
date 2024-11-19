vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = candies[0];

        for(const int candy: candies)
            max_candy = max(candy, max_candy);
        
        vector<bool> ans(candies.size());
        for(int i = 0; i < candies.size(); i++)
            ans[i] = (extraCandies + candies[i] >= max_candy)? true : false;
        

        return ans;
    }
