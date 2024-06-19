int findDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(auto num : nums){
            if(dup.find(num) != dup.end())
                return num;
            dup.insert(num);
        }
        return -1;
    }
