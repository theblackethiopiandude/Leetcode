int minSubArrayLen(int target, vector<int>& nums) {
        int length = numeric_limits<int>::max(), L = 0, total = 0;

        for(int R = 0; R < nums.size(); R++){
            total += nums[R];

            while(total >= target){
                length = min(length, R-L+1);
                total -= nums[L++];
            }
        }
        return (length == INT_MAX)? 0 : length;
    }
