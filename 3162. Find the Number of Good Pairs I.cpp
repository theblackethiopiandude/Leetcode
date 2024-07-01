int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> umap;
        for(int num : nums2)
            umap[num * k]++;
        
        int count = 0;
        for(auto& pair : umap)
            for(int num : nums1)
                if(num % pair.first == 0) count += pair.second;
        
        return count;
    }
