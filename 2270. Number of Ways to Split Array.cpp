int waysToSplitArray(vector<int>& nums) {
        int count = 0, n = nums.size();
        vector<long long> prefix(n+1);
        
        for(int i = 1; i <= n; i++)
            prefix[i] = prefix[i-1] + nums[i-1];


        for(int i = 1; i < n; i++)
            if(prefix[i] >= prefix[n] - prefix[i])
                count++;
        
        return count;
    }
