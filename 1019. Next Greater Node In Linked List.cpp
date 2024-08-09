vector<int> nextLargerNodes(ListNode* head) {
        vector<int> st;
        for(auto curr = head; curr != nullptr; curr = curr->next)
            st.push_back(curr->val);
        vector<int> ans(st.size(), 0);
        vector<int> mon;
        for(int R = st.size()-1; R >=0; R--){
            while(!mon.empty() && mon.back() <= st[R])
                mon.pop_back();
            
            if(!mon.empty())
                ans[R] = mon.back();

            mon.push_back(st[R]);
            
        }
        return ans;
  }
