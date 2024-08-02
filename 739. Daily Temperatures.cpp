vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        {
            stack<pair<int, int>> st;
            for(int R = temperatures.size() -1; R >= 0; R--){
                while(!st.empty() && temperatures[R] >= st.top().first)
                    st.pop();
                ans[R] = (st.empty())? 0 : st.top().second;
                st.push(make_pair(temperatures[R], R));
            }
            for(int L = 0; L < temperatures.size(); L++){
                if(ans[L] == 0)
                    continue;
                ans[L] -= L; 
            }
        }
        return ans;
    }
