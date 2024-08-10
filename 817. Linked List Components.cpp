int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int conn = 0;
        int c = 0;

        for(auto curr = head; curr; curr = curr->next){
            if(uset.count(curr->val)){
                if(c++ == 0)
                    conn++;
            }else{
                c = 0;
            }       
        }
        return conn;
    }
