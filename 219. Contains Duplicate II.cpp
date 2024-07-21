bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++){
            if(umap.count(nums[i]))
                if(abs(umap[nums[i]] - i) <= k)
                    return true;
            
            umap[nums[i]] = i;
        }

        return false;
    }

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;

        {
            unordered_set<int> s;
            for(int i = 0; i < nums.size(); i++){
                if(s.count(nums[i]))
                    return true;
                
                if(s.size() == k)
                    s.erase(nums[i-k]);
                
                s.insert(nums[i]);
            }
        }
        return false;
    }
