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
