bool isPalindrome(ListNode* head) {
        vector<int> normal;
        ListNode *prev = nullptr, *curr = head;
        while(curr){
            normal.push_back(curr->val);
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        curr = prev;
        for(int i = 0; i < normal.size(); i++, curr = curr->next){
            if(normal[i] != curr->val)
                return false;
        }

        return true;
  }

bool isPalindrome(ListNode* head) {
        ListNode *prev = nullptr, *slow = head;
        for(auto fast = head; fast&&fast->next; fast = fast->next->next, slow = slow->next);

        for(auto curr = slow; curr;){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        for(;prev; prev = prev->next, head = head->next)
            if(prev->val != head->val)
                return false;

        return true;
    }
