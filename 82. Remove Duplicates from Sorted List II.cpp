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
