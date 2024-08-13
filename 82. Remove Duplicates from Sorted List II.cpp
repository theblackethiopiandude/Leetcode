ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> umap;
        for(auto curr = head; curr; curr = curr->next)
            umap[curr->val]++;
        
        if(umap.size() == 0)
            return nullptr;

        auto dummy = new ListNode(101);
        auto d = dummy;
        for(auto [val, count]: umap){
            if(count == 1){
                auto node = new ListNode(val);
                d->next = node;
                d = node;
            }
        }

        return dummy->next;
    }

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(101, head);

        for(auto curr = head, prev = dummy; curr; curr = curr->next){
            bool hasDuplicate = false;
            while(curr->next && curr->val == curr->next->val){
                hasDuplicate = true;
                curr = curr->next;
            }

            if (hasDuplicate)
                prev->next = curr->next;
            else
                prev = curr;
        }

        return dummy->next;
    }
