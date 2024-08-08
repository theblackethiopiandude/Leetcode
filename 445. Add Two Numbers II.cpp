ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for(auto curr = l1; curr != nullptr; curr = curr->next)
            s1.push(curr->val);
        
        for(auto curr = l2; curr != nullptr; curr = curr->next)
            s2.push(curr->val);

        int n = min(s1.size(), s2.size());

        ListNode* head = nullptr;
        int rem = 0;
        while(n--){
            int sum = s1.top() + s2.top() + rem;
            rem = (sum > 9)? 1 : 0;
            s1.pop();
            s2.pop();
            
            auto node = new ListNode(sum%10);
            if(head){
                node->next = head; 
            }

            head = node;
        }
        while(!s1.empty()){
            int sum = s1.top() + rem;
            rem = (sum > 9)? 1 : 0;
            s1.pop();
            auto node = new ListNode(sum%10);
            node->next = head;
            head = node;
        }
        while(!s2.empty()){
            int sum = s2.top() + rem;
            rem = (sum > 9)? 1 : 0;
            s2.pop();
            auto node = new ListNode(sum%10);
            node->next = head;
            head = node;
        }
        if(rem){
            auto node = new ListNode(rem);
            node->next = head;
            head = node;
        }

        return head;
    }
