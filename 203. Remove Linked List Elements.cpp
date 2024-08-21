ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1, head);
        for(auto curr = head, prev = dummy; curr; curr = curr->next){
            if(curr->val == val){
                prev->next = curr->next;
                continue;
            }
            prev = curr;
        }
        return dummy->next;
  }
