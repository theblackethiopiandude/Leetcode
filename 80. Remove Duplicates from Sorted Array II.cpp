int removeDuplicates(vector<int>& nums) {
        int L = 0;
        for(int R = 0; R < nums.size(); R++){
            int count = 1;
            while(R+1 < nums.size() && nums[R] == nums[R+1]){
                R++, count++;
            }
            for(int i = 0; i < min(2, count); i++)
                nums[L++] = nums[R];
        }
        return L;
    }
