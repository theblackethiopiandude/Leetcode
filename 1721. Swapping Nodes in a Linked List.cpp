ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        for(auto curr = head; curr; curr = curr->next)
            arr.push_back(curr->val);
        swap(arr[k-1], arr[arr.size()-k]);
        auto nh = new ListNode(arr[0]);
        auto curr = nh;
        for(int i = 1; i < arr.size(); i++, curr = curr->next)
            curr->next = new ListNode(arr[i]);
        
        return nh;
    }
