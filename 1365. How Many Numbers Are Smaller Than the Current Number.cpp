vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> out(nums.size(), 0);

        unordered_map<int, int> umap;

        for(auto num: nums)
            umap[num]++;
        
        for(int i = 0; i < nums.size(); i++){
            int sc = 0;

            for(auto pair : umap)
                if(pair.first < nums[i])
                    sc += pair.second;
            
            out[i] = sc;
        }
        return out;
    }

// unoptimized counting sort
