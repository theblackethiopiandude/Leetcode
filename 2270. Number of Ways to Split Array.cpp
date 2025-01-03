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

int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        
        for(long long i = 0, L = 0, R = accumulate(nums.begin(), nums.end(), 0LL); i < nums.size()-1; i++){
            L += nums[i];
            R -= nums[i];

            if(L >= R)
                count++;
        }

        return count;
    }
