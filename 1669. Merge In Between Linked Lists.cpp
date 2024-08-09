ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *entry = nullptr, *exit = nullptr, *l2end = list2;
        int i = 0;
        for(auto curr = list1; curr != nullptr; curr = curr->next, i++){
            if(i+1 == a)
                entry = curr;
            
            if(i == b){
                exit = curr->next;
                break;
            }
        }

        for(; l2end->next != nullptr; l2end = l2end->next);
        // for(auto curr = list2; curr != nullptr; curr = curr->next)
        //     l2end = curr;

        entry->next = list2;
        l2end->next = exit;
        
        return list1;
  }
