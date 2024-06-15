vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        {
            int sum;
            while(i < j){
                sum = numbers[i] + numbers[j];

                if(target > sum)
                    i++;
                else if(target < sum)
                    j--;
                else
                    break;
            }
        }

        vector<int> ans = {i+1, j+1};
        return ans;
    }
