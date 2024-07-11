ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return nullptr;
        {
            ListNode* p = nullptr;
            auto slow = head;
            auto fast = head;
            while(fast && fast->next){
                p = slow;
                fast = fast->next->next;
                slow = slow->next;
            }
            p->next = slow->next;
        }
        return head;
    }
