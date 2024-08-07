ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        vector<ListNode*> rv;
        while(head){
            rv.push_back(head);
            head = head->next;
        }
        head = rv.back();
        auto curr = head;
        for(int i = rv.size()-2; i>=0; i--){
            rv[i]->next = nullptr;
            curr->next = rv[i];
            curr = curr->next;

        }
        return head;
    }


ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        for(auto curr = head; curr;){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

ListNode* reverseList(ListNode* head) {

        if(head == nullptr)
            return nullptr;
        
        ListNode* newHead = head;
        if(head->next){
            newHead = reverseList(head->next);
            head->next->next = head;
            
        }
        head->next = nullptr;

        return newHead;
    }
