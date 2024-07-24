int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for(int num: nums){
            currSum = max(currSum, 0) + num;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
