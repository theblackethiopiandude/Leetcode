vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++)
            if(!s.count(i))
                ans.push_back(i);
        
        return ans;
    }

vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                ans.push_back(i+1);
        
        return ans;
}
