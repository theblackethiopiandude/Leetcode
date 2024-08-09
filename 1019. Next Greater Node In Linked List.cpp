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

vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = nullptr;
        int n = 0;
        for(auto curr = head; curr != nullptr; n++){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        vector<int> ans(n);
        vector<int> mon;
        for(auto curr = prev; curr != nullptr; curr = curr->next){
            while(!mon.empty() && mon.back() <= curr->val)
                mon.pop_back();
            
            ans[--n] = (mon.empty())? 0 : mon.back();

            mon.push_back(curr->val);
            
        }
        return ans;
}
