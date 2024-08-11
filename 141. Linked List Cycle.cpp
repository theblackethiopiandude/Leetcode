bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> u;
        for(auto curr = head; curr; curr = curr->next){
            if(u.count(curr))
                return true;
            u.insert(curr);
        }
        return false;
    }
