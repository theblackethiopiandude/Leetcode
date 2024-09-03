void moveZeroes(vector<int>& nums) {
        for(int L = 0, R = L+1; R < nums.size(); R++){
            if(nums[L] == 0 & nums[R] != 0)
                swap(nums[L++], nums[R]);
            
            if(nums[L] != 0)
                L++;
        }
    }
