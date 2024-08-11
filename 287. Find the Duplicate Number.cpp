int findDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(auto num : nums){
            if(dup.find(num) != dup.end())
                return num;
            dup.insert(num);
        }
        return -1;
    }

int findDuplicate(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; true;){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow)
                break;
        }
        for(int slow2 = 0; true;){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow2 == slow)
                break;
        }
        return slow;
    }
