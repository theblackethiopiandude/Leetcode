ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0, head);
        auto L = dummy, R = head;
        
        while(n--)
            R = R->next;
                
        while(R){
            L = L->next;
            R = R->next;
        }
        
        L->next = L->next->next;
        return dummy->next;
    } 
