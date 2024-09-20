bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return true;
        
        bool nonIncreasing = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                nonIncreasing = false;
                break;
            }
        }
        
        bool nonDecreasing = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                nonDecreasing = false;
                break;
            }
        }
        
        return nonIncreasing || nonDecreasing;
  }
