ListNode* sortList(ListNode* head) {
        vector<int> nums;
        for(auto curr = head; curr; curr = curr->next)
            nums.push_back(curr->val);
        
        sort(nums.begin(), nums.end());
        auto dummy = new ListNode(0);
        auto curr = dummy;
        for(int num: nums){
            curr->next = new ListNode(num);
            curr = curr->next;
        }

        return dummy->next;
}
