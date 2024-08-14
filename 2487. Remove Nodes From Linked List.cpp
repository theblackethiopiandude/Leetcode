ListNode* removeNodes(ListNode* head) {
        ListNode *prev = nullptr;
        int n = 0;
        for(auto curr = head; curr; n++){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        vector<int> arr(n);
        stack<int> st;
        for(auto curr = prev; curr; curr=curr->next){
            while(!st.empty() && curr->val >= st.top())
                st.pop();
            arr[--n] = (st.empty())? -1 : st.top();
            st.push(curr->val);
        }
        head = prev;
        prev = nullptr;
        for(auto curr = head; curr;){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        auto dummy = new ListNode(-1, head);
        prev = dummy;
        int i = 0;
        for(auto curr = head; curr; curr = curr->next, i++){
            if(arr[i] == -1)
                prev = curr;
            else
                prev->next = curr->next;
        }

        return dummy->next;
  }
