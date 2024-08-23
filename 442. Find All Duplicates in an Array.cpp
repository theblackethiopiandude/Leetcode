vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int num: nums)
            umap[num]++;
        
        vector<int> ans;
        for(auto [_, count] : umap)
            if(count > 1)
                ans.push_back(_);
        
        return ans;
       
  } // bruteforce T:O(n), S:O(n)
