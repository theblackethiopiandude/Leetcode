int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        for(int L = 0, R = 0, flip = k; R < nums.size(); R++){
            if(nums[R] == 0){
                while(flip == 0){
                    if(nums[L++] == 0)
                        flip++;
                }
                flip--;
            }
            count = max(count, R - L + 1);
        }
        return count;
    }
