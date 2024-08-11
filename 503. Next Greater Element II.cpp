vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        for(int R = nums.size()-1; R >= 0; R--){
            while(!st.empty() && st.top() <= nums[R])
                st.pop();
            ans[R] = (st.empty())? -1 : st.top();
            st.push(nums[R]);
        }
        for(int R = nums.size()-1; R >= 0; R--){
            while(!st.empty() && st.top() <= nums[R])
                st.pop();
            ans[R] = (st.empty())? -1 : st.top(), ans[R];
            st.push(nums[R]);
        }
        return ans;
    }
