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

int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int mn=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                mn=min(j-i+1,mn);
                i++;
            }
            j++;
        }
        if(mn==INT_MAX){
            return 0;
        }
        return mn;
    }
