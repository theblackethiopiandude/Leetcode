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

ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *second = head;
        int size = 0;
        for(auto curr = head; curr; curr = curr->next, size++)
            if(size + 1 == k)
                first = curr;
        
        for(int i = 0; i < size-k; i++)
            second = second->next;
        
        swap(first->val, second->val);
        
        return head;
    }
