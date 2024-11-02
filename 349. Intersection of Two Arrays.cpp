vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> one(nums1.begin(), nums1.end()), two(nums2.begin(), nums2.end()), seen;

        for(int x: one)
            if(two.count(x))
                seen.insert(x);
        
        for(int x: two)
            if(one.count(x))
                seen.insert(x);

        return vector<int> (seen.begin(), seen.end());
    }
