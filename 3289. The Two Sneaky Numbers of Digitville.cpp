vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> seen;
        vector<int> ans;

        for(const int num: nums){
            if(seen.count(num))
                ans.push_back(num);
            
            seen.insert(num);
        }

        return ans;
    }
