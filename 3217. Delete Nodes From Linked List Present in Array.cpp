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
