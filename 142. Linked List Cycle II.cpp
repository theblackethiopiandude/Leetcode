ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        for(; fast && fast->next;){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)
            return nullptr;

        for(auto slow2 = head; slow2 && slow; slow = slow->next, slow2 = slow2->next){
            if(slow == slow2)
                break;
        }

        return slow;
    }

ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> us;
        for(auto curr = head; curr; curr = curr->next){
            if(us.count(curr))
                return curr;
            us.insert(curr);
        }

        return nullptr;
    }
