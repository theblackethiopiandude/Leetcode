vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size()), rightSum(nums.size()), ans(nums.size());

        for(int i = 0, sum = 0; i < nums.size(); sum += nums[i++])
            leftSum[i] = sum;
        
        for(int i = nums.size() - 1, sum = 0; i >= 0; sum += nums[i--])
            rightSum[i] = sum;
        
        for(int i = 0; i < nums.size(); i++)
            ans[i] = abs(leftSum[i] - rightSum[i]);

        return ans;
    }
