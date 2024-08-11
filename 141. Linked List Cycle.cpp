bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> u;
        for(auto curr = head; curr; curr = curr->next){
            if(u.count(curr))
                return true;
            u.insert(curr);
        }
        return false;
    }

bool hasCycle(ListNode *head) {
        for(auto slow = head, fast = head; fast && fast->next;){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
