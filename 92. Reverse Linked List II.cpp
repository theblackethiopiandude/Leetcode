ListNode* reverseBetween(ListNode* head, int left, int right) {


        ListNode *entry = nullptr, *exit = nullptr;
        int i = 1;
        for(auto curr = head; curr->next != nullptr; curr = curr->next, i++){
            if(i+1 == left)
                entry = curr;
            
            if(i == right){
                exit = curr->next;
                break;
            }

        }
        ListNode *prev = exit, *curr = (entry)? entry->next : head;
        while(curr != exit){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if(entry)
            entry->next = prev;
        else
            head = prev;

        return head;
    }
