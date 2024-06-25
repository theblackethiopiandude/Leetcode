int removeDuplicates(vector<int>& nums) {
        for(auto it = nums.begin() + 1; it != nums.end();)
            if(*(it - 1) == * it)
                it = nums.erase(it);
            else
                it++;
        return nums.size();
    }
