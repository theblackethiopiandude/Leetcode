ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        for(auto& curr = head->next, i = ans; curr->next != nullptr; curr = curr->next){
            if(curr->val != 0)
                i->val += curr->val;
            else{
               ListNode *node = new ListNode(); 
               i->next = node;
               i = i->next;
            }
        }
        return ans;
    }
