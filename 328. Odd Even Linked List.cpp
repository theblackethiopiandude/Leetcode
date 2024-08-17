ListNode* oddEvenList(ListNode* head) {
        ListNode *even = new ListNode();
        ListNode *odd = new ListNode();
        auto e = even;
        auto o = odd;
        auto curr = head;
        for(int i = 0; curr; i++, curr = curr->next){   
            if((i % 2) == 0){
                e->next = curr;
                e = e->next;
            }
            else{
                o->next = curr;
                o = o->next;
            }
        }

        o->next = nullptr;
        e->next = nullptr;
        e->next = odd->next;
        return even->next;
  }
