int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(const int num: nums)
            umap[num]++;
        
        pair<int, int> ans(0,0);
        int maxc = nums.size() / 2;
        for(const auto& [element, count] : umap)
            if(count > (nums.size() / 2)){
                if(count >= maxc){
                    ans.first = element;
                    ans.second =  count;
                }
            }

        return ans.first;
}
