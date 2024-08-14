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

ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        for(ListNode *curr = head, *ptr = nullptr; curr; curr = curr->next, delete ptr){
            ptr = curr;
            while(!st.empty() && st.back() < curr->val)
                st.pop_back();
            st.push_back(curr->val);
        }
        auto dummy = new ListNode();
        auto curr = dummy;
        for(int num: st){
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;
}

ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        for(auto curr = head; curr; curr = curr->next){
            while(!st.empty() && st.back() < curr->val)
                st.pop_back();
            st.push_back(curr->val);
        }
        auto dummy = new ListNode();
        auto curr = dummy;
        for(int num: st){
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;
}
