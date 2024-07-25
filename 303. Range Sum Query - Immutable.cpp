class NumArray {
public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for(int num: nums){
            total += num;
            sum.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right] - ((left > 0)? sum[left - 1]: 0);
    }
private:
    vector<int> sum;
};
