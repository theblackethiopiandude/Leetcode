ListNode* deleteDuplicates(ListNode* head) {
        for(auto curr = head; curr && curr->next != nullptr; curr = curr->next)
            while(curr->next && curr->val == curr->next->val)
                curr->next = curr->next->next;
            
        return head;
  }
