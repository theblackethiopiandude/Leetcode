class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        int total = 0;
        for(int num: nums){
            total += num;
            sum.push_back(total);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        for(int i = index; i < sum.size(); i++)
            sum[i] += diff;
    }
    
    int sumRange(int left, int right) {
        return sum[right] - ((left > 0)? sum[left-1]: 0);
    }
private:
    vector<int> sum;
    vector<int> nums;
};
