vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> seen; // unordered_set
        vector<int> ans;

        for(const int num: nums){
            if(seen.count(num))
                ans.push_back(num);
            
            seen.insert(num);
        }

        return ans;
    }

vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(const int num: nums)
            umap[num]++;

        vector<int> ans;
        for(const auto& [num, count]: umap)
            if(count == 2)
                ans.push_back(num);

        return ans;
    }
