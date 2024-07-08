int removeDuplicates(vector<int>& nums) {
        for(auto it = nums.begin() + 1; it != nums.end();)
            if(*(it - 1) == * it)
                it = nums.erase(it);
            else
                it++;
        return nums.size();
    }


int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) 
            return 0;
    
        int L = 1, R = 0;
        while(++R < nums.size())
            if(nums[R-1] == nums[R])
                continue;
            else
                nums[L++] = nums[R];
        
        
        
        return L;
    }
