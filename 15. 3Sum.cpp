vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            int l = i+1, r = n-1;

            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum < 0)
                    l++;
                else if(sum > 0)
                    r--;
                
                else{
                   ans.push_back({nums[i], nums[l], nums[r]});
                   int tl = l, tr = r;
                   while(l < r && nums[l] == nums[tl]) l++;
                   while(l < r && nums[r] == nums[tr]) r--;
                }
            }

            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
    
        return ans;
    }
