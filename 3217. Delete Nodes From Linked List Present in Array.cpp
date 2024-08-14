ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(), nums.end());
        
        for(auto curr = head, prev = curr; curr != nullptr; ){     
            if(uset.count(curr->val)){
                if(curr->next == nullptr){
                    prev->next = nullptr;
                    break;    
                }

                curr->val = curr->next->val;
                curr->next = curr->next->next;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }

        return head;
}

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(), nums.end());
        
        for(ListNode *curr = head, *prev = nullptr; curr != nullptr; curr = curr->next){     
            if(uset.count(curr->val)){
                if(prev){
                    prev->next = curr->next;
                }else{
                    head = curr->next;
                }
                
                continue;
            }
            prev = curr;
        }

        return head;
}

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(), nums.end());
        auto dummy = new ListNode(-1, head);
        for(ListNode *curr = head, *prev = dummy; curr ; curr = curr->next){     
            if(uset.count(curr->val)){
                prev->next = curr->next;
                continue;
            }
            prev = curr;
        }

        return dummy->next;
}
